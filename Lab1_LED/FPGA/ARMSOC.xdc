set_property IOSTANDARD LVCMOS33 [get_ports CLK]
set_property PACKAGE_PIN T5 [get_ports CLK]
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports {CLK}];

set_property IOSTANDARD LVCMOS33 [get_ports RESET]
set_property PACKAGE_PIN P15 [get_ports RESET]

set_property IOSTANDARD LVCMOS33 [get_ports TCK]
set_property IOSTANDARD LVCMOS33 [get_ports TDI]
set_property IOSTANDARD LVCMOS33 [get_ports TDO]
set_property IOSTANDARD LVCMOS33 [get_ports TMS]
set_property SLEW FAST [get_ports TDO]
set_property SLEW FAST [get_ports TMS]
set_property PACKAGE_PIN G18 [get_ports TMS]
set_property PACKAGE_PIN J17 [get_ports TDI]
set_property PACKAGE_PIN J18 [get_ports TDO]
set_property PACKAGE_PIN F18 [get_ports TCK]
create_clock -period 20.000 -name dbg_tck_pin -waveform {0.000 10.000} -add [get_ports TCK]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets TCK]

set_property IOSTANDARD LVCMOS33 [get_ports {LED[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LED[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LED[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LED[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LED[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LED[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LED[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {LED[0]}]
set_property PACKAGE_PIN F6 [get_ports {LED[7]}]
set_property PACKAGE_PIN G4 [get_ports {LED[6]}]
set_property PACKAGE_PIN G3 [get_ports {LED[5]}]
set_property PACKAGE_PIN J4 [get_ports {LED[4]}]
set_property PACKAGE_PIN H4 [get_ports {LED[3]}]
set_property PACKAGE_PIN J3 [get_ports {LED[2]}]
set_property PACKAGE_PIN J2 [get_ports {LED[1]}]
set_property PACKAGE_PIN K2 [get_ports {LED[0]}]

set_property IOSTANDARD LVCMOS33 [get_ports {KEY[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {KEY[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {KEY[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {KEY[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {KEY[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {KEY[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {KEY[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {KEY[0]}]
set_property PACKAGE_PIN P5 [get_ports {KEY[7]}]
set_property PACKAGE_PIN P4 [get_ports {KEY[6]}]
set_property PACKAGE_PIN P3 [get_ports {KEY[5]}]
set_property PACKAGE_PIN P2 [get_ports {KEY[4]}]
set_property PACKAGE_PIN R2 [get_ports {KEY[3]}]
set_property PACKAGE_PIN M4 [get_ports {KEY[2]}]
set_property PACKAGE_PIN N4 [get_ports {KEY[1]}]
set_property PACKAGE_PIN R1 [get_ports {KEY[0]}]
