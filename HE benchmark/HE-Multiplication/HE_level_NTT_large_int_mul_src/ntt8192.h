/*
 * NTT for Q=12289 and n=8192
 */

#ifndef __NTT8192_H
#define __NTT8192_H

#include "ntt8192_tables.h"
#include "ntt.h"
#include "ap_int.h"



/*
 * NTT VARIANTS
 *
 * - the input a is an array of n integers that must be between 0 and Q-1
 * - the result is stored in place
 * - the inverse transforms return a result scaled by n:
 *    we have intt(ntt(a)) = n * a
 */
// forward
static inline void ntt8192_ct_std2rev(ap_int<128> *a) {
  ntt_ct_std2rev(a, 8192, ntt8192_omega_powers_rev);
}

// inverse
static inline void intt8192_ct_rev2std(ap_int<128> *a) {
  ntt_ct_rev2std(a, 8192, ntt8192_inv_omega_powers);
}


/*
 * PRODUCTS
 */

/*
 * Input: two arrays a and b in standard order
 * Result: 
 * - the product is stored in array c, in standard order.
 * - arrays a and b are modified
 *
 * The input arrays must contain elements in the range [0 .. Q-1]
 * The result is also in that range.
 */
extern void ntt8192_int_product(ap_int<128> *c, ap_int<128> *a, ap_int<128> *b);

#endif /* __ntt8192_H */
