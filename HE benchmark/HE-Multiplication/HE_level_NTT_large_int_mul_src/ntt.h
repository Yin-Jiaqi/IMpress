/*
 * BD: variant implementations of NTT
 *
 * All variants are specialized to Q=12289.
 * - omega denotes a primitive n-th root of unity (mod Q).
 * - psi denotes a square root of omega (mod Q).
 */

#ifndef __NTT_H
#define __NTT_H

#include <stdint.h>
#include <ap_int.h>


/*************
 * UTILITIES *
 ************/

/*
 * Shuffle a: swap a[i] and a[j] where j = bit-reverse i
 * - generic version for arbitrary n
 */
extern void bitrev_shuffle(ap_int<128> *a, ap_uint<128> n);

/*
 * Bit-Reverse using a pre-computed table of pairs [i, j] with i<j and j = bit-reverse(i)
 * - p = the table
 * - n = number of pairs in p
 */
extern void shuffle_with_table(ap_int<128> *a, const ap_uint<128> p[][2], ap_uint<128> n);

/*
 * In-place elementwise product: a[i] = a[i] * p[i] mod Q
 * - a[i] and p[i] must be between 0 and Q-1
 * - p is assumed to be a array of 16bit constants (e.g., p[i] = psi^i mod Q)
 */
extern void mul_array16(ap_int<128> *a, ap_uint<128> n, const ap_uint<128> *p);

/*
 * Elementwise product: c[i] = a[i] * b[i]
 * - all arrays are 32bit integers of size n
 * - a[i] and b[i] must be between 0 and Q-1
 */
extern void mul_array(ap_int<128> *c, ap_uint<128> n, ap_int<128> *a, ap_int<128> *b);

/*
 * Product by a scalar c: a[i] = c * a[i]
 * - a[i] must be between 0 and Q-1
 * - c must be between 0 and Q-1
 * - the product is done in place.
 */
extern void scalar_mul_array(ap_int<128> *a, ap_uint<128> n, ap_int<128> c);


/****************
 * NTT VARIANTS *
 ***************/

/*
 * COOLEY-TUKEY: BIT-REVERSE TO STANDARD ORDER
 */

/*
 * Version 1
 * - input: a[0 ... n-1] in bit-reverse order
 * - p: constant array of powers of psi: p[i] = psi^i modulo Q
 * - output: a contains the NTT(a) in standard order.
 *
 * This is based on ntt_blzzd.c
 */
extern void ntt_ct_rev2std_v1(ap_int<128> *a, ap_uint<128> n, const ap_uint<128> *p);

/*
 * Version 2: different precomputed powers
 * - input: a[0 ... n-1] in bit-reverse order
 * - p: array of powers of omega
 *   such that p[t + j] = omega^(n/2t)^j
 *   for t=1, 2, 4, .., n/2
 *   and j=0, ..., t-1.
 *
 * This array looks like this:
 *   p[0] --> not used
 *   p[1] --> 1
 *   p[2] --> 1, omega^(n/4)
 *   p[4] --> 1, omega^(n/8), omega^(2*n/8), omega^(3*n/8)
 *   p[8] --> 1, omega^(n/16), ....
 *
 * - output: a contains the NTT(a) in standard order
 */
extern void ntt_ct_rev2std(ap_int<128> *a, ap_uint<128> n, const ap_uint<128> *p);

/*
 * COOLEY-TUKEY: STANDARD TO BIT-REVERSE ORDER
 */

/*
 * Version 4
 * - input a[0 ... n-1] in standard order
 * - p: constant array such that
 *   p[t + j] = omega^(n/2t)^ bitrev(j)
 *   for t=1, 2, 4, ..., n/2
 *   and j=0, ..., t-1.
 *
 * - output: NTT(a) in bit-reverse order
 */
extern void ntt_ct_std2rev(ap_int<128> *a, ap_uint<128> n, const ap_uint<128> *p);

#endif /* __NTT_H */
