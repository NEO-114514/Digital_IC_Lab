
w
Command: %s
53*	vivadotcl2F
2link_design -top ARMSOC_TOP -part xc7a100tcsg324-12default:defaultZ4-113h px� 
g
#Design is defaulting to srcset: %s
437*	planAhead2
	sources_12default:defaultZ12-437h px� 
j
&Design is defaulting to constrset: %s
434*	planAhead2
	constrs_12default:defaultZ12-434h px� 
W
Loading part %s157*device2$
xc7a100tcsg324-12default:defaultZ21-403h px� 
�
-Reading design checkpoint '%s' for cell '%s'
275*project2j
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_25M/clk_25M.dcp2default:default2
	u_clk_25M2default:defaultZ1-454h px� 
�
-Reading design checkpoint '%s' for cell '%s'
275*project2j
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_50M/clk_50M.dcp2default:default2
	u_clk_50M2default:defaultZ1-454h px� 
g
-Analyzing %s Unisim elements for replacement
17*netlist2
3882default:defaultZ29-17h px� 
j
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px� 
�
�Netlist '%s' is not ideal for floorplanning, since the cellview '%s' defined in file '%s' contains large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.
43*netlist2

ARMSOC_TOP2default:default2$
cortexm3ds_logic2default:default2"
ARMSOC_TOP.edf2default:defaultZ29-43h px� 
x
Netlist was created with %s %s291*project2
Vivado2default:default2
2019.12default:defaultZ1-479h px� 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px� 
�
NRemoving redundant IBUF since it is not being driven by a top-level port. %s 
32*opt2/
u_clk_25M/inst/clkin1_ibufg2default:defaultZ31-32h px� 
�
�Could not create '%s' constraint because net '%s' is not directly connected to top level port. Synthesis is ignored for %s but preserved for implementation.
528*constraints2 
IBUF_LOW_PWR2default:default2'
u_clk_25M/clk_in12default:default2 
IBUF_LOW_PWR2default:default8Z18-550h px� 
�
$Parsing XDC File [%s] for cell '%s'
848*designutils2r
\d:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_25M/clk_25M_board.xdc2default:default2$
u_clk_25M/inst	2default:default8Z20-848h px� 
�
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2r
\d:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_25M/clk_25M_board.xdc2default:default2$
u_clk_25M/inst	2default:default8Z20-847h px� 
�
$Parsing XDC File [%s] for cell '%s'
848*designutils2l
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_25M/clk_25M.xdc2default:default2$
u_clk_25M/inst	2default:default8Z20-848h px� 
�
%Done setting XDC timing constraints.
35*timing2l
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_25M/clk_25M.xdc2default:default2
572default:default8@Z38-35h px� 
�
Deriving generated clocks
2*timing2l
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_25M/clk_25M.xdc2default:default2
572default:default8@Z38-2h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2 
get_clocks: 2default:default2
00:00:082default:default2
00:00:082default:default2
1377.6602default:default2
564.6802default:defaultZ17-268h px� 
�
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2l
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_25M/clk_25M.xdc2default:default2$
u_clk_25M/inst	2default:default8Z20-847h px� 
�
$Parsing XDC File [%s] for cell '%s'
848*designutils2r
\d:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_50M/clk_50M_board.xdc2default:default2$
u_clk_50M/inst	2default:default8Z20-848h px� 
�
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2r
\d:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_50M/clk_50M_board.xdc2default:default2$
u_clk_50M/inst	2default:default8Z20-847h px� 
�
$Parsing XDC File [%s] for cell '%s'
848*designutils2l
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_50M/clk_50M.xdc2default:default2$
u_clk_50M/inst	2default:default8Z20-848h px� 
�
Deriving generated clocks
2*timing2l
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_50M/clk_50M.xdc2default:default2
572default:default8@Z38-2h px� 
�
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2l
Vd:/Digital_IC/Digital_IC_Lab/Lab3_UART/Lab3_UART.srcs/sources_1/ip/clk_50M/clk_50M.xdc2default:default2$
u_clk_50M/inst	2default:default8Z20-847h px� 
�
Parsing XDC File [%s]
179*designutils2L
6D:/Digital_IC/Digital_IC_Lab/Lab3_UART/FPGA/ARMSOC.xdc2default:default8Z20-179h px� 
�
Finished Parsing XDC File [%s]
178*designutils2L
6D:/Digital_IC/Digital_IC_Lab/Lab3_UART/FPGA/ARMSOC.xdc2default:default8Z20-178h px� 
u
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0042default:default2
1377.6602default:default2
0.0002default:defaultZ17-268h px� 
�
!Unisim Transformation Summary:
%s111*project2�
�  A total of 5 instances were transformed.
  IOBUF => IOBUF (IBUF, OBUFT): 1 instances
  RAM32M => RAM32M (RAMD32, RAMD32, RAMD32, RAMD32, RAMD32, RAMD32, RAMS32, RAMS32): 4 instances
2default:defaultZ1-111h px� 
�
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
122default:default2
32default:default2
02default:default2
02default:defaultZ4-41h px� 
]
%s completed successfully
29*	vivadotcl2
link_design2default:defaultZ4-42h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2!
link_design: 2default:default2
00:00:192default:default2
00:00:182default:default2
1377.6602default:default2
989.2932default:defaultZ17-268h px� 
~
4The following parameters have non-default value.
%s
395*common2&
general.maxThreads2default:defaultZ17-600h px� 


End Record