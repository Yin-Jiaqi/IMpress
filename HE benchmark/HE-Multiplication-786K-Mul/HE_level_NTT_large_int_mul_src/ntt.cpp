/*
 * NTT and Inverse NTT.
 *
 * All variants are specialized to Q
 * In all variants, we assume: omega is a primitive n-th
 * root of unity and psi^2 = omega.
 */

#include <assert.h>

#if 0
#include <stdio.h>
#include <inttypes.h>
#endif

#include "ntt.h"
#include <ap_int.h>
#include <iostream>
using namespace std;

//#define Q 163841
ap_uint<260> Q = "115763822272329310636028559609001827025179711501300126126825041166177555972097"; // (2^64-2^50)^4+1



/*
 * UTILITIES
 */

// inner multiplication unit 1 (replace this unit 1 with the optimized multiplier)
ap_int<1040> multiplication_520(ap_int<520> x, ap_int<520> y){
    ap_uint<1040> result = x * y;
    return result;
}

// inner multiplication unit 2 (replace this unit 2 with the optimized multiplier)
ap_int<520> multiplication_260(ap_int<260> x, ap_int<260> y){
    ap_uint<520> result = x * y;
    return result;
}

/*
 * Bit-reverse shuffle: generic form
 */
void bitrev_shuffle(ap_int<260> *a, ap_uint<260> n) {
  ap_uint<32> i, j, k;
  ap_int<260> x;

  assert(n > 0 && (n & (n - 1)) == 0); // n must be a power of 2

  j = n>>1;
  for (i=1; i<n-1; i++) {
    if (i < j) {
      x = a[i]; a[i] = a[j]; a[j] = x;
    }
    k = n;
    do {
      k >>= 1;
      j ^= k;
    } while ((j & k) == 0);
  }
}

/*
 * Bit-Reverse using a pre-computed table of pairs [i, j] with i<j and j = bit-reverse(i)
 * - n = number of pairs in the table
 */
void shuffle_with_table(ap_int<260> *a, const ap_uint<260> p[][2], ap_uint<260> n) {
  ap_uint<32> i, j, k;
  ap_int<260> x;

  for (i=0; i<n; i++) {
    j = p[i][0];
    k = p[i][1];
    x = a[j]; a[j] = a[k]; a[k] = x;
  }
}


/*
 * REDUCTIONS MODULO Q
 */

/*
 * x and y are assumed to be between 0 and q-1
 */
static inline ap_int<520> sub_mod(ap_int<520> x, ap_int<520> y) {

  ap_int<520> r1 = (x - y) + Q;
  ap_int<520> r2 = (x - y);
  ap_int<520> res = (x - y) < 0 ? r1 : r2;
  assert(0<=res<Q);
  return res; 

  //std::cout << "x: " << x  << " y: " << y << "\n";
  //x -= y;
  //std::cout << " res: " << (x < 0 ? (ap_int<260>)(x + Q) : x) << "\n";
  // return x < 0 ? (ap_int<260>)(x + Q) : x;
  // return x + ((x >> 31) & Q); // x + Q * sign(x)
  //return x + ((x >> 14) & Q); // shift by 14 is enough
}

static inline ap_int<520> add_mod(ap_int<520> x, ap_int<520> y) {
  ap_int<520> r1 = (x + y) - Q;
  ap_int<520> r2 = (x + y);
  ap_int<520> res = (x + y) >= Q ? r1 : r2;
  assert(0<=res<Q);
  return res; 
  //x += y;
  //return x - Q >= 0 ? (ap_int<260>)(x - Q) : x;
  //x += y - Q;
  //return x + ((x >> 14) & Q);
}

/*
 * approximation of division by modulus 
 */
static inline ap_uint<520> divq(ap_int<520> x) {
  return multiplication_520(x,"115820363104470734023613986825982863910250770655763738897334064472562687038240") >> 512;
}

static inline ap_int<260> modq(ap_int<520> x) {
  ap_int<261> res1 = (ap_int<261>)((ap_int<261>)x - (ap_int<261>)(multiplication_520(divq(x), Q)));
  ap_int<260> res2 = (res1 > Q) ? (ap_int<260>)(res1 - Q) : (ap_int<260>)res1;
  return res2; 
}


/*
 * ELEMENTWISE PRODUCTS
 */

/*
 * In-place product: a[i] = a[i] * p[i]
 * - a[i] and p[i] must be between 0 and Q-1
 * - p is assumed to be a array of 16bit constants (e.g., p[i] = psi^i mod Q)
 */
void mul_array16(ap_int<260> *a, ap_uint<260> n, const ap_uint<260> *p) {
  ap_uint<32> i;

  for (i=0; i<n; i++) {
    a[i] = modq((ap_int<520>)a[i] * p[i]);
  }
}

/*
 * Elementwise product: c[i] = a[i] * b[i]
 * - all arrays are 32bit integers of size n
 */
void mul_array(ap_int<260> *c, ap_uint<260> n, ap_int<260> *a, ap_int<260> *b) {
  ap_uint<32> i;

  for (i=0; i<n; i++) {
    c[i] = modq(multiplication_260(a[i],b[i]));
    /*std::cout << "a[" << i << "]=" << a[i] << "  ";
    std::cout << "b[" << i << "]=" << b[i] << "  ";
    std::cout << "c[" << i << "]=" << c[i] << "  ";
    std::cout << "\n";*/
  }
}


/*
 * PRODUCT BY A SCALAR
 */
/*
 * In-place product: a[i] = a[i] * c
 * - all elements must be in the range [0 ... q-1] and c too
 */
void scalar_mul_array(ap_int<260> *a, ap_uint<260> n, ap_int<260> c) {
  ap_uint<32> i;

  for (i=0; i<n; i++) {
    a[i] = modq(multiplication_260(a[i], c));
  }
}


/*
 * COOLEY-TUKEY/INPUT IN BIT-REVERSE ORDER/OUTPUT IN STANDARD ORDER
 */

/*
 * Version 1:
 * - input: a[0 ... n-1] in bit-reverse order
 * - p: constant array of powers of psi: p[i] = psi^i modulo Q
 * - output: a contains the NTT(a) in standard order.
 *
 * This is the same procedure as in ntt_blzzd.
 */
void ntt_ct_rev2std_v1(ap_int<260> *a, ap_uint<260> n, const ap_uint<260> *p) {
  ap_uint<32> j, s, t, l;
  ap_int<260> x, w;

  for (t=1, l = n; t<n; t <<= 1, l >>= 1) {
    /*
     * invariant: n = l * t 
     *
     * Each iteration processes l blocks of size t
     * to produce l/2 blocks of size 2t
     * The w_t for round t is omega^(n/2t) = psi^(n/t) = psi^l
     */
    // first loop: j=0 so w_t^j = 1
    for (s=0; s<n; s += t + t) {
      x = a[s + t];
      a[s + t] = sub_mod(a[s], x);
      a[s] = add_mod(a[s], x);
    }
    // general case: j>0
    for (j=1; j<t; j++) {
      w = p[j*l]; // w_t^j = psi^l*j
      for (s=j; s<n; s += t + t) {
        //	x = (a[s + t] * w) % Q;
        x = modq(multiplication_260(a[s + t], w));
        a[s + t] = sub_mod(a[s], x);
        a[s] = add_mod(a[s], x);
      }
    }    
  }
}


/*
 * Version 2:
 * - input: a[0 ... n-1] in bit-reverse order
 * - p: constant array of powers of omega
 *   such that p[t + j] = omega^(n/2t)^j
 *   for t=1, 2, 4, .., n/2
 *       j=0, ..., t-1
 *   this array looks like:
 *     p[0] --> not used
 *     p[1] --> 1
 *     p[2] --> 1, omega^(n/4)
 *     p[4] --> 1, omega^(n/8), omega^(2*n/8), omega^(3*n/8)
 *     p[8] --> 1, ...
 *
 * - output: a contains the NTT(a) in standard order
 */
void ntt_ct_rev2std(ap_int<260> *a, ap_uint<260> n, const ap_uint<260> *p) {
  ap_uint<32> j, s, t;
  ap_int<260> x, w;

  for (t=1; t<n; t <<= 1) {
    /*
     * process m blocks of size t to produce m/2 blocks of size 2t
     * - m = n/t
     * - w_t for this round is omega^(n/2t) = p[t]
     */
    // first loop: j=0 so w_t^j = 1
    for (s=0; s<n; s += t + t) {
      x = a[s + t];
      a[s + t] = sub_mod(a[s], x);
      a[s] = add_mod(a[s], x);
    }
    // general case: j>0
    for (j=1; j<t; j++) {
      w = p[t+j];   // w_t^j
      for (s=j; s<n; s += t + t) {
        //	x = (a[s + t] * w) % Q;
        x = modq(multiplication_260(a[s + t], w));        
        a[s + t] = sub_mod(a[s], x);
        a[s] = add_mod(a[s], x);
      }
    }
  }
  //for (t=0; t<n; t++) {
    //std::cout << "a[" << t << "]: " << a[t] << "\n ";
    //std::cout << "w: " << w << " "; 
    //std::cout << "x: " << x << "\n"; 
  //}

}



/*
 * COOLEY-TUKEY/INPUT IN STANDARD ORDER/OUTPUT IN BIT-REVERSE ORDER
 */

/*
 * Version 4:
 * - input: a[0 ... n-1] in standard order
 * - p: constant array ow powers of omega
 *   such that p[t + j] = omega^(n/2t)^ bitrev(j)
 *   for t=1, 2. 4, ..., n/2
 *   and j=0, ..., t-1.
 *
 * - output: NTT(a) in bit-reverse order
 */
void ntt_ct_std2rev(ap_int<260> *a, ap_uint<260> n, const ap_uint<260> *p) {
  ap_uint<32> j, s, t, u, d;
  ap_int<260> x, w;

  d = n;
  for (t=1; t<n; t <<= 1) {
    d >>= 1;
    /*
     * Invariant: d * 2t = n.
     *
     * Each iteration produces d blocks of size 2t.
     * Block i is stored at indices {i, i+d, ..., i+d*(2t-1) } in
     * bit-reverse order.
     *
     * The w_t for this round is omega^(n/2t).
     * and w_t,j is w_t^bitrev(j)
     */
    // first loop: j=0, bitrev(j) = 0
    for (s=0; s<d; s ++) {
      x = a[s + d];
      a[s + d] = sub_mod(a[s], x);
      a[s] = add_mod(a[s], x);
    }
    u = 0;
    for (j=1; j<t; j++) {
      w = p[t + j]; // w_t^bitrev(j)
      u += 2 * d;   // u = 2 * d * j
      for (s=u; s<u+d; s++) {
        x = modq(multiplication_260(a[s + d], w));
        a[s + d] = sub_mod(a[s], x);
        a[s] = add_mod(a[s], x);
      }
    }
  }
}











