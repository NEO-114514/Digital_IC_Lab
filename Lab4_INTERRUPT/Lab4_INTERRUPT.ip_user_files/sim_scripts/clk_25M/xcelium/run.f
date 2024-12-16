-makelib xcelium_lib/xil_defaultlib -sv \
  "E:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "E:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../Lab4_INTERRUPT.srcs/sources_1/ip/clk_25M/clk_25M_clk_wiz.v" \
  "../../../../Lab4_INTERRUPT.srcs/sources_1/ip/clk_25M/clk_25M.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

