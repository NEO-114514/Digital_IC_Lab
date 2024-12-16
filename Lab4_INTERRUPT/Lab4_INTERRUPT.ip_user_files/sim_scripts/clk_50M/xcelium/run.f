-makelib xcelium_lib/xil_defaultlib -sv \
  "E:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "E:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../Lab4_INTERRUPT.srcs/sources_1/ip/clk_50M/clk_50M_clk_wiz.v" \
  "../../../../Lab4_INTERRUPT.srcs/sources_1/ip/clk_50M/clk_50M.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

