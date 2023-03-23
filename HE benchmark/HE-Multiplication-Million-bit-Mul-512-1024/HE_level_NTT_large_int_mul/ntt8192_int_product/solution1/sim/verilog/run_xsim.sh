
/media/asyam/bce327c2-015d-448b-a5ee-db0952816570/opt/Vivado/2020.2/bin/xelab xil_defaultlib.apatb_ntt8192_int_product_top glbl -prj ntt8192_int_product.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm  -L floating_point_v7_0_18 -L floating_point_v7_1_11 --lib "ieee_proposed=./ieee_proposed" -s ntt8192_int_product 
/media/asyam/bce327c2-015d-448b-a5ee-db0952816570/opt/Vivado/2020.2/bin/xsim --noieeewarnings ntt8192_int_product -tclbatch ntt8192_int_product.tcl 

