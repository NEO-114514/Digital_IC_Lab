//////////////////////////////////////////////////////////////////////////////////
//END USER LICENCE AGREEMENT                                                    //
//                                                                              //
//Copyright (c) 2012, ARM All rights reserved.                                  //
//                                                                              //
//THIS END USER LICENCE AGREEMENT ("LICENCE") IS A LEGAL AGREEMENT BETWEEN      //
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

module BAUDGEN
(
  input wire clk,
  input wire resetn,
  output reg baudtick,
  input wire baudcontrol
);


reg [21:0] count_reg;
reg [21:0] count_next;

//Counter
always @ (posedge clk, negedge resetn)
  begin
    if(!resetn)
      count_reg <= 0;
    else
      count_reg <= count_next;
end


// Baudrate  = 19200 = 50Mhz/(163*16)
// assign count_next = ((count_reg == 162) ? 0 : count_reg + 1'b1);

// assign baudtick = ((count_reg == 162) ? 1'b1 : 1'b0);


// Baudrate  = 19200 = 25Mhz/(163*8)
// Baudrate  = 57600 = 25Mhz/(54*8)
// Baudrate  = 115200 = 25Mhz/(27*8)
// Baudrate  = 230400 = 25Mhz/(13.5*8)


// assign count_next = ((count_reg == 162) ? 0 : count_reg + 1'b1);

// assign baudtick = ((count_reg == 162) ? 1'b1 : 1'b0);


always @*
begin
  case (baudcontrol)

    2'b00:  count_next <= ((count_reg == 162) ? 0 : count_reg + 1'b1);
    2'b01:  count_next <= ((count_reg == 53) ? 0 : count_reg + 1'b1);
    2'b10:  count_next <= ((count_reg == 26) ? 0 : count_reg + 1'b1);
    2'b11:  count_next <= ((count_reg == 12) ? 0 : count_reg + 1'b1);

    default:  count_next <= ((count_reg == 162) ? 0 : count_reg + 1'b1);

  endcase

end

always @*
begin
  case (baudcontrol)

    2'b00:  baudtick <= ((count_reg == 162) ? 1'b1 : 1'b0);
    2'b01:  baudtick <= ((count_reg == 53) ? 1'b1 : 1'b0);
    2'b10:  baudtick <= ((count_reg == 26) ? 1'b1 : 1'b0);
    2'b11:  baudtick <= ((count_reg == 12) ? 1'b1 : 1'b0);

    default:  baudtick <= ((count_reg == 162) ? 1'b1 : 1'b0);

  endcase

end

endmodule
