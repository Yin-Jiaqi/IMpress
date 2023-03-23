open_project ntt16384_int_product
set_top ntt16384_int_product
add_files ../HE_level_NTT_large_int_mul_src/ntt16384.cpp
add_files ../HE_level_NTT_large_int_mul_src/ntt16384.h
add_files ../HE_level_NTT_large_int_mul_src/ntt.cpp
add_files ../HE_level_NTT_large_int_mul_src/ntt.h
add_files ../HE_level_NTT_large_int_mul_src/ntt16384_tables.cpp
add_files ../HE_level_NTT_large_int_mul_src/ntt16384_tables.h

#add_files -tb ../HE_level_NTT_large_int_mul_src/test_ntt16384.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb ../HE_level_NTT_large_int_mul_src/test_ntt16384_768K_mul.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb ../HE_level_NTT_large_int_mul_src/sort.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb ../HE_level_NTT_large_int_mul_src/sort.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vitis
set_part {xcvu11p-flga2577-1-e}
create_clock -period 2.5 -name default
csim_design
#csynth_design
#cosim_design
#export_design -flow impl -rtl verilog -format syn_dcp
exit
