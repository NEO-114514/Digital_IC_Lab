// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Thu Nov 14 14:55:22 2024
// Host        : HUNTER running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               d:/Digital_IC/Digital_IC_Lab/Lab2_VGA_4096/Lab2_VGA_4096.srcs/sources_1/ip/clk_25M/clk_25M_stub.v
// Design      : clk_25M
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
module clk_25M(clk_out1, resetn, clk_in1)
/* synthesis syn_black_box black_box_pad_pin="clk_out1,resetn,clk_in1" */;
  output clk_out1;
  input resetn;
  input clk_in1;
endmodule
