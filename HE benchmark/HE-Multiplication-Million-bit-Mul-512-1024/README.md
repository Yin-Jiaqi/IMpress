# 1Million and 768K Multiplier used in integer based FHE

Inner multiplication units are named as `multiplication_512` and `multiplication_1024`.


This folder contains VHLS source files and VHLS script and test files for the VHLS experiments.

This benchmark is based on Jorge Navas, Bruno Dutertre and Ian Mason, "Verification of an Optimized NTT Algorithm", VSTTE20 Conference, 2020.
Their C-level optimized codes for CPU is here:  https://github.com/SRI-CSL/NTT
They recently publish these implementations and the results in VSTTE20 conference.


## In order to run the NTT-based very large integer multiplication benchmark:

```bat
cd HE_level_NTT_large_int_mul
vitis_hls -f tcl_script.tcl
```

Source codes are in `HE_level_NTT_large_int_mul_src` folder.


## Interface


```c
void ntt8192_int_product(ap_int<512> c[8192], ap_int<512> a[8192], ap_int<512> b[8192]) {
#pragma HLS INTERFACE s_axilite port=a 
#pragma HLS INTERFACE s_axilite port=b 
#pragma HLS INTERFACE m_axi port=c offset=slave 
...
```

### Encoding
This design can perform 1007616-bit or 786432-bit integer multiplication and it accepts `a` and `b` as 1007616-bit or 786432-bit input operands.
The input operands are first encoded into polynomials of degree 8192 with 512-bit coefficients.

Since we are using 8192-point NTT, input operands of multiplication operation can carry N/2=4096 coefficients and the rest 4096 coefficient of the input polynomials need to be padded with zero.
Also considering the limit of NTT due to the selected prime, we can set the base as 246-bit. 
Thus, we can encode 4096*240-bit (1007616-bit) operands or we can encode  4096*192-bit (786432-bit) operands as polynomials with prime 52374250506775412587080182017685909013279339260195121351951847958786555732255090462694066661827009813312276859354987266719224819790981416185422168457217 value and NTT-8192.
Current test function tests 4096*240-bit encoding and thus tests 1million-bit input operand multiplication. The [expected_result.h](https://github.com/cornell-zhang/fhe-xcel/tree/main/HE-Multiplication-Million-bit-Mul-512-1024/HE_level_NTT_large_int_mul_src/expected_result.h) contains the expected result for the an input given in the Test code.



## Verification
The results are verified with a Python implementation of multiplication of two 1007616-bit multiplication.


After C Simulation, a similar test output should be visible on the console.
```
1M Integer Multiplication using NTT Test starts (integers are mapped to polynomials)
Our test passed.

Finished
```

## Latency Results
Cosim:
````
Report time       : Thu Jan  6 13:23:10 +03 2022.
Solution          : solution1.
Simulation tool   : xsim.

+----------+----------+-----------------------------------------------+-----------------------------------------------+----------------------+
|          |          |             Latency(Clock Cycles)             |              Interval(Clock Cycles)           | Total Execution Time |
+   RTL    +  Status  +-----------------------------------------------+-----------------------------------------------+    (Clock Cycles)    +
|          |          |      min      |      avg      |      max      |      min      |      avg      |      max      |                      |
+----------+----------+-----------------------------------------------+-----------------------------------------------+----------------------+
|      VHDL|        NA|             NA|             NA|             NA|             NA|             NA|             NA|                    NA|
|   Verilog|      Pass|       54265038|       54265038|       54265038|             NA|             NA|             NA|              54265038|
+----------+----------+-----------------------------------------------+-----------------------------------------------+----------------------+
````

## Area Results
Csynth:
````
================================================================
== Performance Estimates
================================================================
+ Timing: 
    * Summary: 
    +--------+---------+----------+------------+
    |  Clock |  Target | Estimated| Uncertainty|
    +--------+---------+----------+------------+
    |ap_clk  |  2.50 ns|  2.028 ns|     0.68 ns|
    +--------+---------+----------+------------+
    
================================================================
== Utilization Estimates
================================================================
* Summary: 
+---------------------+---------+-------+---------+---------+-----+
|         Name        | BRAM_18K|  DSP  |    FF   |   LUT   | URAM|
+---------------------+---------+-------+---------+---------+-----+
|DSP                  |        -|      -|        -|        -|    -|
|Expression           |        -|      -|        0|     1418|    -|
|FIFO                 |        -|      -|        -|        -|    -|
|Instance             |      480|  11671|    57952|    20418|    -|
|Memory               |        -|      -|        -|        -|    -|
|Multiplexer          |        -|      -|        -|     2017|    -|
|Register             |        -|      -|    12349|       64|    -|
+---------------------+---------+-------+---------+---------+-----+
|Total                |      480|  11671|    70301|    23917|    0|
+---------------------+---------+-------+---------+---------+-----+
|Available SLR        |     1344|   3072|   864000|   432000|  320|
+---------------------+---------+-------+---------+---------+-----+
|Utilization SLR (%)  |       35|    379|        8|        5|    0|
+---------------------+---------+-------+---------+---------+-----+
|Available            |     4032|   9216|  2592000|  1296000|  960|
+---------------------+---------+-------+---------+---------+-----+
|Utilization (%)      |       11|    126|        2|        1|    0|
+---------------------+---------+-------+---------+---------+-----+
````


