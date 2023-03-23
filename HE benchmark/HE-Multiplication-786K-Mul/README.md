# 768K Multiplier used in integer based FHE

Inner multiplication units are named as `multiplication_260` and `multiplication_520`.

This folder contains VHLS source files and VHLS script and test files for the VHLS experiments.

This benchmark is based on Jorge Navas, Bruno Dutertre and Ian Mason, "Verification of an Optimized NTT Algorithm", VSTTE20 Conference, 2020.
Their C-level optimized codes for CPU is here:  https://github.com/SRI-CSL/NTT
They recently publish these implementations and the results in VSTTE20 conference.


## In order to run the NTT-based integer multiplication benchmark:

```bat
cd HE_level_NTT_large_int_mul
vitis_hls -f tcl_script.tcl
```

Source codes are in `HE_level_NTT_large_int_mul_src` folder.


## Interface


```c
void ntt16384_int_product(ap_int<260> c[16384], ap_int<260> a[16384], ap_int<260> b[16384]) {
#pragma HLS INTERFACE s_axilite port=a 
#pragma HLS INTERFACE s_axilite port=b 
#pragma HLS INTERFACE m_axi port=c offset=slave 
...

```

### Encoding
786432-bit integer multiplication unit accepts `a` and `b` as 786432-bit input operands.
The input operands are first encoded into polynomials of degree 16384 with 260-bit coefficients.

Since we are using 16384-point NTT, input operands of multiplication operation can carry N/2=8192 coefficients and the rest 8192 coefficient of the input polynomials need to be padded with zero.
Also considering the limit of NTT due to the selected prime, we can set the base as 96-bit. 
Thus, we can encode 8192*96-bit (786432-bit) operands as polynomials with prime 115763822272329310636028559609001827025179711501300126126825041166177555972097 value and NTT-16384.



## Verification
The results are verified with a Python implementation of multiplication of two 786432-bit multiplication.


After C Simulation, a similar test output should be visible on the console.
```
768K Integer Multiplication using NTT Test starts (integers are mapped to polynomials)
Our test passed.

Finished
```

## Latency Results
Cosim:
````
Report time       : Sun Dec  4 02:06:30 +03 2022.
Solution          : solution1.
Simulation tool   : xsim.

+----------+----------+-----------------------------------------------+-----------------------------------------------+----------------------+
|          |          |             Latency(Clock Cycles)             |              Interval(Clock Cycles)           | Total Execution Time |
+   RTL    +  Status  +-----------------------------------------------+-----------------------------------------------+    (Clock Cycles)    +
|          |          |      min      |      avg      |      max      |      min      |      avg      |      max      |                      |
+----------+----------+-----------------------------------------------+-----------------------------------------------+----------------------+
|      VHDL|        NA|             NA|             NA|             NA|             NA|             NA|             NA|                    NA|
|   Verilog|      Pass|      116107458|      116107458|      116107458|             NA|             NA|             NA|             116107458|
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
+---------------------+---------+------+---------+---------+-----+
|         Name        | BRAM_18K|  DSP |    FF   |   LUT   | URAM|
+---------------------+---------+------+---------+---------+-----+
|DSP                  |        -|     -|        -|        -|    -|
|Expression           |        -|     -|        0|      732|    -|
|FIFO                 |        -|     -|        -|        -|    -|
|Instance             |      486|  2405|    40711|    17189|    -|
|Memory               |        -|     -|        -|        -|    -|
|Multiplexer          |        -|     -|        -|     2035|    -|
|Register             |        -|     -|     5796|       64|    -|
+---------------------+---------+------+---------+---------+-----+
|Total                |      486|  2405|    46507|    20020|    0|
+---------------------+---------+------+---------+---------+-----+
|Available SLR        |     1344|  3072|   864000|   432000|  320|
+---------------------+---------+------+---------+---------+-----+
|Utilization SLR (%)  |       36|    78|        5|        4|    0|
+---------------------+---------+------+---------+---------+-----+
|Available            |     4032|  9216|  2592000|  1296000|  960|
+---------------------+---------+------+---------+---------+-----+
|Utilization (%)      |       12|    26|        1|        1|    0|
+---------------------+---------+------+---------+---------+-----+
````


