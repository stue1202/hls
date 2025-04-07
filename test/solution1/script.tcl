############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project test
set_top KAN
add_files test/Cppversion/CKANv2.cpp
add_files test/add_axi.h
add_files test/Cppversion/kan_paras.h
add_files test/test.cpp
open_solution "solution1"
set_part {xc7z020-clg484-1}
create_clock -period 10 -name default
set_clock_uncertainty 12.5%
#source "./test/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog
