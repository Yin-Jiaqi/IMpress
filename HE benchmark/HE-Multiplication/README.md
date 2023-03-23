# Very Large Integer Multiplication using NTT for FHE computation using very large inner integer multiplication units

This folder includes very large integer multiplication for HE in the frequency domain using NTT transform with 128, or more large inner multiplications.
It includes the VHLS scripts and test files for the VHLS experiments.

This benchmark is based on Jorge Navas, Bruno Dutertre and Ian Mason, "Verification of an Optimized NTT Algorithm", VSTTE20 Conference, 2020.
Their C-level optimized codes for CPU is here:  https://github.com/SRI-CSL/NTT
They recently publish these implementations and the results in VSTTE20 conference.


## In order to run the NTT-based integer multiplication benchmark:

```bat
cd HE_level_NTT_large_int_mul
vitis_hls -f tcl_script.tcl
```

Source codes of the HE_level_NTT_large_int_mul implementation is in `HE_level_NTT_large_int_mul_src` folder.


## Interface


```c
void ntt8192_int_product(ap_int<128> c[8192], ap_int<128> a[8192], ap_int<128> b[8192]) {
#pragma HLS INTERFACE s_axilite port=a 
#pragma HLS INTERFACE s_axilite port=b 
#pragma HLS INTERFACE m_axi port=c offset=slave 
...

```

## NTT-based Integer Multiplication Experiment Results 
Target Device: xcvu11p-flga2577-1-e
Target clock period: 2.5 ns 

Synthesis Results:
```
================================================================
== Utilization Estimates
================================================================
* Summary: 
+---------------------+---------+------+---------+---------+-----+
|         Name        | BRAM_18K|  DSP |    FF   |   LUT   | URAM|
+---------------------+---------+------+---------+---------+-----+
|DSP                  |        -|     -|        -|        -|    -|
|Expression           |        -|     -|        0|     8193|    -|
|FIFO                 |        -|     -|        -|        -|    -|
|Instance             |      144|   527|    25328|    49675|    -|
|Memory               |        -|     -|        -|        -|    -|
|Multiplexer          |        -|     -|        -|     1727|    -|
|Register             |        -|     -|    45704|      160|    -|
+---------------------+---------+------+---------+---------+-----+
|Total                |      144|   527|    71032|    59755|    0|
+---------------------+---------+------+---------+---------+-----+
|Available SLR        |     1344|  3072|   864000|   432000|  320|
+---------------------+---------+------+---------+---------+-----+
|Utilization SLR (%)  |       10|    17|        8|       13|    0|
+---------------------+---------+------+---------+---------+-----+
|Available            |     4032|  9216|  2592000|  1296000|  960|
+---------------------+---------+------+---------+---------+-----+
|Utilization (%)      |        3|     5|        2|        4|    0|
+---------------------+---------+------+---------+---------+-----+
```

### Encoding
163840-bit integers are first encoded into polynomials.

Since we are using 8192-point NTT, our polynomials for each multiplication operands can carry N/2=4096 coefficients.
Also considering the limit of NTT due to the selected prime, we can set the base as 40-bit. 
Thus, we can encode 4096*40-bit (163840-bit) operands as polynomials with prime 85236826359346144956638323529482240001 value and NTT-8192.



## Verification
The results are verified with a Python implementation of multiplication of two 163840-bit multiplication.


After C Simulation, a similar test output should be visible on the console.
```
160K Integer Multiplication using NTT Test starts (integers are mapped to polynomials)
Our test passed.

Finished
```


