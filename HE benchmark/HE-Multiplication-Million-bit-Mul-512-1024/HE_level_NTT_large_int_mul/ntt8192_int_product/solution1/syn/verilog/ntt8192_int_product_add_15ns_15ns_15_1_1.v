// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps

module ntt8192_int_product_add_15ns_15ns_15_1_1_Adder_11(a, b, s);

input [15 - 1 : 0] a;
input [15 - 1 : 0] b;
output [15 - 1 : 0] s;

assign s = a + b;

endmodule
`timescale 1 ns / 1 ps
module ntt8192_int_product_add_15ns_15ns_15_1_1(
    din0,
    din1,
    dout);

parameter ID = 32'd1;
parameter NUM_STAGE = 32'd1;
parameter din0_WIDTH = 32'd1;
parameter din1_WIDTH = 32'd1;
parameter dout_WIDTH = 32'd1;
input[din0_WIDTH - 1:0] din0;
input[din1_WIDTH - 1:0] din1;
output[dout_WIDTH - 1:0] dout;



ntt8192_int_product_add_15ns_15ns_15_1_1_Adder_11 ntt8192_int_product_add_15ns_15ns_15_1_1_Adder_11_U(
    .a( din0 ),
    .b( din1 ),
    .s( dout ));

endmodule

