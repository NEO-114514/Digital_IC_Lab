//////////////////////////////////////////////////////////////////////////////////
//END USER LICENCE AGREEMENT                                                    //
//                                                                              //
//Copyright (c) 2012, ARM All rights reserved.                                  //
//                                                                              //
//THIS END USER LICENCE AGREEMENT (“LICENCE”) IS A LEGAL AGREEMENT BETWEEN      //
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


module vga_image(
  input wire clk,
  input wire resetn,
  input wire [9:0] pixel_x,
  input wire [9:0] pixel_y,
  input wire image_we,
  input wire [11:0] image_data,

  input wire [16:0] address,
  output wire [11:0] image_rgb,

  input wire [9:0] text_width,

  input wire [2:0] image_zoom

  );


  reg [16:0] addr_r;
  wire [15:0] addr_w;

  wire [11:0] din;
  wire [11:0] dout;
  
  wire [9:0] img_x;
  wire [9:0] img_y;

  reg [16:0] address_reg;

 //buffer address = bus address -1 , as the first address is used for console
  always @(posedge clk)
  begin
    if(!resetn)
      address_reg <= 17'b0_0000_0000_0000_0000;
    else 
      address_reg <= address-1;
  end


//Frame buffer

 dual_port_ram_sync
  #(.ADDR_WIDTH(16), .DATA_WIDTH(12))
  uimage_ram
  ( .clk(clk),
    .reset_n(resetn),
    .we(image_we),
    .addr_a(addr_w),
    .addr_b(addr_r),
    .din_a(din),
    .dout_a(),
    .dout_b(dout)
  ); 


  assign addr_w = address_reg[15:0];
  assign din = image_data;
  
  assign img_x = pixel_x[9:0]-text_width;
  assign img_y = pixel_y[9:0];

  always @*
  begin
    // case (image_zoom)
    //   3'b000:  addr_r <= {1'b0, img_y[8:0], img_x[9:0]}; 
    //   3'b001:  addr_r <= {2'b0, img_y[8:1], 1'b0, img_x[9:1]};
    //   3'b010:  addr_r <= {3'b0, img_y[8:2], 2'b0, img_x[9:2]};

    //   default:  addr_r <= {1'b0, img_y[8:0], img_x[9:0]};
    // endcase
    addr_r = {1'b0, img_y[8:2], img_x[9:2]}; 
  end

  // assign addr_r = {1'b0, img_y[8:0], img_x[9:0]}; 

  assign image_rgb = dout;

endmodule
