//////////////////////////////////////////////////////////////////////////////////
//END USER LICENCE AGREEMENT                                                    //
//                                                                              //
//Copyright (c) 2012, ARM All rights reserved.                                  //
//                                                                              //
//THIS END USER LICENCE AGREEMENT (�LICENCE�) IS A LEGAL AGREEMENT BETWEEN      //
//YOU AND ARM LIMITED ("ARM") FOR THE USE OF THE SOFTWARE EXAMPLE ACCOMPANYING  //
//THIS LICENCE. ARM IS ONLY WILLING TO LICENSE THE SOFTWARE EXAMPLE TO YOU ON   //
//CONDITION THAT YOU ACCEPT ALL OF THE TERMS IN THIS LICENCE. BY INSTALLING OR  //
//OTHERWISE USING OR COPYING THE SOFTWARE EXAMPLE YOU INDICATE THAT YOU AGREE   //
//TO BE BOUND BY ALL OF THE TERMS OF THIS LICENCE. IF YOU DO NOT AGREE TO THE   //
//TERMS OF THIS LICENCE, ARM IS UNWILLING TO LICENSE THE SOFTWARE EXAMPLE TO    //
//YOU AND YOU MAY NOT INSTALL, USE OR COPY THE SOFTWARE EXAMPLE.                //
//                                                                              //
//ARM hereby grants to you, subject to the terms and conditions of this Licence,//
//a non-exclusive, worldwide, non-transferable, copyright licence only to       //
//redistribute and use in source and binary forms, with or without modification,//
//for academic purposes provided the following conditions are met:              //
//a) Redistributions of source code must retain the above copyright notice, this//
//list of conditions and the following disclaimer.                              //
//b) Redistributions in binary form must reproduce the above copyright notice,  //
//this list of conditions and the following disclaimer in the documentation     //
//and/or other materials provided with the distribution.                        //
//                                                                              //
//THIS SOFTWARE EXAMPLE IS PROVIDED BY THE COPYRIGHT HOLDER "AS IS" AND ARM     //
//EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING     //
//WITHOUT LIMITATION WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR //
//PURPOSE, WITH RESPECT TO THIS SOFTWARE EXAMPLE. IN NO EVENT SHALL ARM BE LIABLE/
//FOR ANY DIRECT, INDIRECT, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES OF ANY/
//KIND WHATSOEVER WITH RESPECT TO THE SOFTWARE EXAMPLE. ARM SHALL NOT BE LIABLE //
//FOR ANY CLAIMS, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, //
//TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE    //
//EXAMPLE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE EXAMPLE. FOR THE AVOIDANCE/
// OF DOUBT, NO PATENT LICENSES ARE BEING LICENSED UNDER THIS LICENSE AGREEMENT.//
//////////////////////////////////////////////////////////////////////////////////


module AHBVGA(
  input wire HCLK,
  input wire VGACLK,
  input wire HRESETn,
  input wire [31:0] HADDR,
  input wire [31:0] HWDATA,
  input wire HREADY,
  input wire HWRITE,
  input wire [1:0] HTRANS,
  input wire HSEL,
  
  output wire [31:0] HRDATA,
  output wire HREADYOUT,
  
  output wire hsync,
  output wire vsync,
  output wire [7:0] rgb
);
  //Register locations
  localparam IMAGEADDR = 4'hA;
  localparam CONSOLEADDR = 4'h0;
  
  //Internal AHB signals
  reg last_HWRITE;
  reg last_HSEL;
  reg [1:0] last_HTRANS;
  reg [31:0] last_HADDR;
  
  wire [7:0] console_rgb; //console rgb signal
  // wire [11:0] console_rgb; //console rgb signal
  
  wire [9:0] pixel_x;     //current x pixel
  wire [9:0] pixel_y;     //current y pixel
  
  reg console_write;      //write to console
  reg [7:0] console_wdata;//data to write to console

  reg image_write;        //write to image
  reg [7:0] image_wdata;  //data to write to image
  // reg [11:0] image_wdata;  //data to write to image
  
  wire [7:0] image_rgb;   //image color
  // wire [11:0] image_rgb;   //image color

  wire scroll;            //scrolling signal
  
  wire sel_console;       
  wire sel_image;
  wire sel_coruse;
  wire sel_text_color;
  wire sel_text_width;
  wire sel_image_zoom;
  
  reg [7:0] cin;
  //reg [11:0] cin;

  reg [6:0] r_cursor_x;
  reg [4:0] r_cursor_y;

  reg [7:0] r_text_color;
  reg [7:0] r_text_back_color; 

  reg [9:0] r_text_width;
  
  reg [2:0] r_image_zoom;

  always @(posedge HCLK)
  if(HREADY)
    begin
      last_HADDR <= HADDR;
      last_HWRITE <= HWRITE;
      last_HSEL <= HSEL;
      last_HTRANS <= HTRANS;
    end
    
  //Give time for the screen to refresh before writing
  assign HREADYOUT = ~scroll;   
 
  //VGA interface: control the synchronization and color signals for a particular resolution
  VGAInterface uVGAInterface (
    .CLK(VGACLK), 
    .COLOUR_IN(cin), 
    .cout(rgb), 
    .hs(hsync), 
    .vs(vsync), 
    .addrh(pixel_x), 
    .addrv(pixel_y)
    );

  //VGA console module: output the pixels in the text region
  vga_console 
    uvga_console
    (
    .clk(HCLK),
    .resetn(HRESETn),
    .address(last_HADDR),
    .pixel_x(pixel_x),
    .pixel_y(pixel_y),

    .font_we(console_write),
    .font_data(console_wdata),

    .text_rgb(console_rgb),
    .scroll(scroll),

    .cursor_x(r_cursor_x),
    .cursor_y(r_cursor_y),

    .text_color(r_text_color),
    .text_back_color(r_text_back_color),

    .r_MAX_X(r_text_width[9:3])
    );

  //VGA image buffer: output the pixels in the image region
  vga_image uvga_image(
    .clk(HCLK),
    .resetn(HRESETn),
    .pixel_x(pixel_x),
    .pixel_y(pixel_y),
    .image_we(image_write),
    .image_data(image_wdata),
    .address(last_HADDR[20:2]),
    .image_rgb(image_rgb),

    .text_width(r_text_width),
    .image_zoom(r_image_zoom)
    );


  //地址选择写文字数据还是图像数据
  assign sel_console = (last_HADDR[23:0] == 0);
  assign sel_image = (last_HADDR[22:0] != 23'b000_0000_0000_0000_0000_0000) && (last_HADDR[23] != 1'b1);
  
  assign sel_coruse = (last_HADDR == 32'h5080_0000);
  assign sel_text_color = (last_HADDR==32'h5080_0004);
  assign sel_text_width = (last_HADDR==32'h5080_0008);
  assign sel_image_zoom = (last_HADDR == 32'h5080_0010);

  //Set console write and write data
  always @(posedge HCLK, negedge HRESETn)
  begin
    if(!HRESETn)
      begin
        console_write <= 0;
        console_wdata <= 0;
      end
    else if(last_HWRITE & last_HSEL & last_HTRANS[1] & HREADYOUT & sel_console)
      begin
        console_write <= 1'b1;
        console_wdata <= HWDATA[7:0];
        // console_wdata <= HWDATA[11:0];
      end
    else
      begin
        console_write <= 1'b0;
        console_wdata <= 0;
      end
  end

  //Set cursor place
  always @(posedge HCLK or negedge HRESETn)
  begin
    if(!HRESETn)
    begin
        r_cursor_x <= 7'b000_0000;
        r_cursor_y <= 5'b0_0000;
    end
    else if (last_HWRITE & last_HSEL & last_HTRANS[1] & HREADYOUT & sel_coruse )
    begin
        r_cursor_x <= HWDATA[6:0];
        r_cursor_y <= HWDATA[11:7];
    end
  end

  //Set text color and background color
  always @(posedge HCLK or negedge HRESETn)
  begin
    if(!HRESETn)
    begin
        r_text_color <= 8'b1111_1111;
        r_text_back_color <= 8'b0000_0000;
    end
    else if (last_HWRITE & last_HSEL & last_HTRANS[1] & HREADYOUT & sel_text_color )
    begin
      r_text_color <= HWDATA[7:0];
      r_text_back_color <= HWDATA[15:8];
    end
  end

  //Set text region width
  always @(posedge HCLK or negedge HRESETn)
  begin
    if(!HRESETn)
      r_text_width <= 9'b0_1111_0000;
    else if (last_HWRITE & last_HSEL & last_HTRANS[1] & HREADYOUT & sel_text_width )
      r_text_width <= HWDATA[9:0];
  end

  //Set image zoom
  always @(posedge HCLK or negedge HRESETn)
  begin
    if(!HRESETn)
      r_image_zoom <= 3'b000;
    else if (last_HWRITE & last_HSEL & last_HTRANS[1] & HREADYOUT & sel_image_zoom )
      r_image_zoom <= HWDATA[2:0];
  end


  //assign HRDATA = {22'b00_0000_0000_0000_0000_0000,r_cursor_y,r_cursor_x};

  //Set image write and image write data
  always @(posedge HCLK, negedge HRESETn)
  begin
    if(!HRESETn)
      begin
        image_write <= 0;
        image_wdata <= 0;
      end
    else if(last_HWRITE & last_HSEL & last_HTRANS[1] & HREADYOUT & sel_image)
      begin
        image_write <= 1'b1;
        image_wdata <= HWDATA[7:0];
        // image_wdata <= HWDATA[11:0];
      end
    else
      begin
        image_write <= 1'b0;
        image_wdata <= 0;
      end
  end
  
  //Select the rgb color for a particular region
  always @*
  begin
    if(!HRESETn)
      cin <= 8'h00;
    else 
      if(pixel_x[9:0]< r_text_width )
        cin <= console_rgb ;
      else
        cin <= image_rgb;
  end

endmodule
  
  
