@echo off
REM ****************************************************************************
REM Vivado (TM) v2019.1 (64-bit)
REM
REM Filename    : elaborate.bat
REM Simulator   : Xilinx Vivado Simulator
REM Description : Script for elaborating the compiled design
REM
REM Generated by Vivado on Sun Nov 10 22:13:39 +0800 2024
REM SW Build 2552052 on Fri May 24 14:49:42 MDT 2019
REM
REM Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
REM
REM usage: elaborate.bat
REM
REM ****************************************************************************
echo "xelab -wto 826e0c5ae8304044952d321ec24762fb --incr --debug typical --relax --mt 16 -L xil_defaultlib -L unisims_ver -L secureip --snapshot ARMSOC_TOP_TB_func_impl xil_defaultlib.ARMSOC_TOP_TB xil_defaultlib.glbl -log elaborate.log"
call xelab  -wto 826e0c5ae8304044952d321ec24762fb --incr --debug typical --relax --mt 16 -L xil_defaultlib -L unisims_ver -L secureip --snapshot ARMSOC_TOP_TB_func_impl xil_defaultlib.ARMSOC_TOP_TB xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0