// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Fri Dec 27 15:25:12 2024
// Host        : HUNTER running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               d:/Digital_IC/Digital_IC_Lab/Lab4_INTERRUPT/Lab4_INTERRUPT.srcs/sources_1/ip/ila_0/ila_0_stub.v
// Design      : ila_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "ila,Vivado 2019.1" *)
module ila_0(clk, probe0, probe1, probe2, probe3)
/* synthesis syn_black_box black_box_pad_pin="clk,probe0[7:0],probe1[7:0],probe2[0:0],probe3[0:0]" */;
  input clk;
  input [7:0]probe0;
  input [7:0]probe1;
  input [0:0]probe2;
  input [0:0]probe3;
endmodule
