open_project ntt8192_int_product
set_top ntt8192_int_product
add_files ../HE_level_NTT_large_int_mul_src/ntt8192.cpp
add_files ../HE_level_NTT_large_int_mul_src/ntt8192.h
add_files ../HE_level_NTT_large_int_mul_src/ntt.cpp
add_files ../HE_level_NTT_large_int_mul_src/ntt.h
add_files ../HE_level_NTT_large_int_mul_src/ntt8192_tables.cpp
add_files ../HE_level_NTT_large_int_mul_src/ntt8192_tables.h
#add_files -tb ../HE_level_NTT_large_int_mul_src/test_ntt8192.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb ../HE_level_NTT_large_int_mul_src/test_ntt8192_160K_mul.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb ../HE_level_NTT_large_int_mul_src/sort.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb ../HE_level_NTT_large_int_mul_src/sort.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vitis
set_part {xcvu11p-flga2577-1-e}
create_clock -period 2.5 -name default
csim_design
csynth_design
#cosim_design
#export_design -flow impl -rtl verilog -format syn_dcp
exit
