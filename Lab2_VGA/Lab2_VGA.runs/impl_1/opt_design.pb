
O
Command: %s
53*	vivadotcl2

opt_design2default:defaultZ4-113h px� 
�
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2"
Implementation2default:default2
xc7a100t2default:defaultZ17-347h px� 
�
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
xc7a100t2default:defaultZ17-349h px� 
n
,Running DRC as a precondition to command %s
22*	vivadotcl2

opt_design2default:defaultZ4-22h px� 
R

Starting %s Task
103*constraints2
DRC2default:defaultZ18-103h px� 
Q
Running DRC with %s threads
24*drc2
162default:defaultZ23-27h px� 
U
DRC finished with %s
272*project2
0 Errors2default:defaultZ1-461h px� 
d
BPlease refer to the DRC report (report_drc) for more information.
274*projectZ1-462h px� 
�

%s
*constraints2s
_Time (s): cpu = 00:00:02 ; elapsed = 00:00:00.675 . Memory (MB): peak = 1398.633 ; gain = 0.0002default:defaulth px� 
g

Starting %s Task
103*constraints2,
Cache Timing Information2default:defaultZ18-103h px� 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px� 
8
Deriving generated clocks
2*timingZ38-2h px� 
O
:Ending Cache Timing Information Task | Checksum: fe3a3977
*commonh px� 
�

%s
*constraints2t
`Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.604 . Memory (MB): peak = 1425.230 ; gain = 26.5982default:defaulth px� 
a

Starting %s Task
103*constraints2&
Logic Optimization2default:defaultZ18-103h px� 
i

Phase %s%s
101*constraints2
1 2default:default2
Retarget2default:defaultZ18-101h px� 
w
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
682default:default2
732default:defaultZ31-138h px� 
K
Retargeted %s cell(s).
49*opt2
02default:defaultZ31-49h px� 
<
'Phase 1 Retarget | Checksum: 125cd3d34
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
�
.Phase %s created %s cells and removed %s cells267*opt2
Retarget2default:default2
4492default:default2
6922default:defaultZ31-389h px� 
�
�In phase %s, %s netlist objects are constrained preventing optimization. Please run opt_design with -debug_log to get more detail. 510*opt2
Retarget2default:default2
12default:defaultZ31-1021h px� 
u

Phase %s%s
101*constraints2
2 2default:default2(
Constant propagation2default:defaultZ18-101h px� 
v
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
52default:default2
182default:defaultZ31-138h px� 
H
3Phase 2 Constant propagation | Checksum: 12c03fe80
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
�
.Phase %s created %s cells and removed %s cells267*opt2(
Constant propagation2default:default2
2322default:default2
5722default:defaultZ31-389h px� 
f

Phase %s%s
101*constraints2
3 2default:default2
Sweep2default:defaultZ18-101h px� 
9
$Phase 3 Sweep | Checksum: 14cb5968e
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:04 ; elapsed = 00:00:03 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
�
.Phase %s created %s cells and removed %s cells267*opt2
Sweep2default:default2
02default:default2
5852default:defaultZ31-389h px� 
r

Phase %s%s
101*constraints2
4 2default:default2%
BUFG optimization2default:defaultZ18-101h px� 
�
4Inserted BUFG %s to drive %s load(s) on clock net %s141*opt2&
TCK_IBUF_BUFG_inst2default:default2
3272default:default2!
TCK_IBUF_BUFG2default:defaultZ31-194h px� 
W
!Inserted %s BUFG(s) on clock nets140*opt2
12default:defaultZ31-193h px� 
h
2Optimized connectivity to %s cascaded buffer cells194*opt2
22default:defaultZ31-274h px� 
D
/Phase 4 BUFG optimization | Checksum: f077765e
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:04 ; elapsed = 00:00:03 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
�
EPhase %s created %s cells of which %s are BUFGs and removed %s cells.395*opt2%
BUFG optimization2default:default2
12default:default2
12default:default2
22default:defaultZ31-662h px� 
|

Phase %s%s
101*constraints2
5 2default:default2/
Shift Register Optimization2default:defaultZ18-101h px� 
�
dSRL Remap converted %s SRLs to %s registers and converted %s registers of register chains to %s SRLs546*opt2
02default:default2
02default:default2
02default:default2
02default:defaultZ31-1064h px� 
N
9Phase 5 Shift Register Optimization | Checksum: f077765e
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:04 ; elapsed = 00:00:03 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
�
.Phase %s created %s cells and removed %s cells267*opt2/
Shift Register Optimization2default:default2
02default:default2
02default:defaultZ31-389h px� 
x

Phase %s%s
101*constraints2
6 2default:default2+
Post Processing Netlist2default:defaultZ18-101h px� 
K
6Phase 6 Post Processing Netlist | Checksum: 117e73cb9
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:05 ; elapsed = 00:00:03 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
�
.Phase %s created %s cells and removed %s cells267*opt2+
Post Processing Netlist2default:default2
02default:default2
02default:defaultZ31-389h px� 
/
Opt_design Change Summary
*commonh px� 
/
=========================
*commonh px� 


*commonh px� 


*commonh px� 
�
z-------------------------------------------------------------------------------------------------------------------------
*commonh px� 
�
�|  Phase                        |  #Cells created  |  #Cells Removed  |  #Constrained objects preventing optimizations  |
-------------------------------------------------------------------------------------------------------------------------
*commonh px� 
�
�|  Retarget                     |             449  |             692  |                                              1  |
|  Constant propagation         |             232  |             572  |                                              0  |
|  Sweep                        |               0  |             585  |                                              0  |
|  BUFG optimization            |               1  |               2  |                                              0  |
|  Shift Register Optimization  |               0  |               0  |                                              0  |
|  Post Processing Netlist      |               0  |               0  |                                              0  |
-------------------------------------------------------------------------------------------------------------------------
*commonh px� 


*commonh px� 


*commonh px� 
a

Starting %s Task
103*constraints2&
Connectivity Check2default:defaultZ18-103h px� 
�

%s
*constraints2s
_Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.085 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
J
5Ending Logic Optimization Task | Checksum: 11a505c95
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:05 ; elapsed = 00:00:04 . Memory (MB): peak = 1550.723 ; gain = 0.0002default:defaulth px� 
a

Starting %s Task
103*constraints2&
Power Optimization2default:defaultZ18-103h px� 
s
7Will skip clock gating for clocks with period < %s ns.
114*pwropt2
2.002default:defaultZ34-132h px� 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px� 
�
(%s %s Timing Summary | WNS=%s | TNS=%s |333*physynth2
	Estimated2default:default2
 2default:default2
11.5222default:default2
0.0002default:defaultZ32-619h px� 
K
,Running Vector-less Activity Propagation...
51*powerZ33-51h px� 
=
Applying IDT optimizations ...
9*pwroptZ34-9h px� 
?
Applying ODC optimizations ...
10*pwroptZ34-10h px� 
P
3
Finished Running Vector-less Activity Propagation
1*powerZ33-1h px� 


*pwropth px� 
e

Starting %s Task
103*constraints2*
PowerOpt Patch Enables2default:defaultZ18-103h px� 
�
�WRITE_MODE attribute of %s BRAM(s) out of a total of %s has been updated to save power.
    Run report_power_opt to get a complete listing of the BRAMs updated.
129*pwropt2
02default:default2
982default:defaultZ34-162h px� 
e
+Structural ODC has moved %s WE to EN ports
155*pwropt2
402default:defaultZ34-201h px� 
�
CNumber of BRAM Ports augmented: %s newly gated: %s Total Ports: %s
65*pwropt2
562default:default2
402default:default2
1962default:defaultZ34-65h px� 
M
8Ending PowerOpt Patch Enables Task | Checksum: 8df3fd85
*commonh px� 
�

%s
*constraints2s
_Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.471 . Memory (MB): peak = 1959.676 ; gain = 0.0002default:defaulth px� 
I
4Ending Power Optimization Task | Checksum: 8df3fd85
*commonh px� 
�

%s
*constraints2q
]Time (s): cpu = 00:00:26 ; elapsed = 00:00:13 . Memory (MB): peak = 1959.676 ; gain = 408.9532default:defaulth px� 
\

Starting %s Task
103*constraints2!
Final Cleanup2default:defaultZ18-103h px� 
D
/Ending Final Cleanup Task | Checksum: 8df3fd85
*commonh px� 
�

%s
*constraints2o
[Time (s): cpu = 00:00:00 ; elapsed = 00:00:00 . Memory (MB): peak = 1959.676 ; gain = 0.0002default:defaulth px� 
b

Starting %s Task
103*constraints2'
Netlist Obfuscation2default:defaultZ18-103h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0162default:default2
1959.6762default:default2
0.0002default:defaultZ17-268h px� 
J
5Ending Netlist Obfuscation Task | Checksum: 6080245d
*commonh px� 
�

%s
*constraints2s
_Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.016 . Memory (MB): peak = 1959.676 ; gain = 0.0002default:defaulth px� 
Z
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px� 
�
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
412default:default2
32default:default2
02default:default2
02default:defaultZ4-41h px� 
\
%s completed successfully
29*	vivadotcl2

opt_design2default:defaultZ4-42h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2 
opt_design: 2default:default2
00:00:362default:default2
00:00:202default:default2
1959.6762default:default2
561.0432default:defaultZ17-268h px� 
~
4The following parameters have non-default value.
%s
395*common2&
general.maxThreads2default:defaultZ17-600h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0062default:default2
1959.6762default:default2
0.0002default:defaultZ17-268h px� 
H
&Writing timing data to binary archive.266*timingZ38-480h px� 
D
Writing placer database...
1603*designutilsZ20-1893h px� 
=
Writing XDEF routing.
211*designutilsZ20-211h px� 
J
#Writing XDEF routing logical nets.
209*designutilsZ20-209h px� 
J
#Writing XDEF routing special nets.
210*designutilsZ20-210h px� 
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2)
Write XDEF Complete: 2default:default2
00:00:002default:default2 
00:00:00.0302default:default2
1959.6762default:default2
0.0002default:defaultZ17-268h px� 
�
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2a
MD:/Digital_IC/Digital_IC_Lab/Lab2_VGA/Lab2_VGA.runs/impl_1/ARMSOC_TOP_opt.dcp2default:defaultZ17-1381h px� 
�
%s4*runtcl2�
pExecuting : report_drc -file ARMSOC_TOP_drc_opted.rpt -pb ARMSOC_TOP_drc_opted.pb -rpx ARMSOC_TOP_drc_opted.rpx
2default:defaulth px� 
�
Command: %s
53*	vivadotcl2w
creport_drc -file ARMSOC_TOP_drc_opted.rpt -pb ARMSOC_TOP_drc_opted.pb -rpx ARMSOC_TOP_drc_opted.rpx2default:defaultZ4-113h px� 
>
IP Catalog is up to date.1232*coregenZ19-1839h px� 
Q
Running DRC with %s threads
24*drc2
162default:defaultZ23-27h px� 
�
#The results of DRC are in file %s.
168*coretcl2�
SD:/Digital_IC/Digital_IC_Lab/Lab2_VGA/Lab2_VGA.runs/impl_1/ARMSOC_TOP_drc_opted.rptSD:/Digital_IC/Digital_IC_Lab/Lab2_VGA/Lab2_VGA.runs/impl_1/ARMSOC_TOP_drc_opted.rpt2default:default8Z2-168h px� 
\
%s completed successfully
29*	vivadotcl2

report_drc2default:defaultZ4-42h px� 


End Record