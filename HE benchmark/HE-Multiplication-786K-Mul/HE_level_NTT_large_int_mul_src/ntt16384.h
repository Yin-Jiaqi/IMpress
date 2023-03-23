/*
 * NTT for Q and n=16384
 */

#ifndef __NTT16384_H
#define __NTT16384_H

#include "ntt16384_tables.h"
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
static inline void ntt16384_ct_std2rev(ap_int<260> *a) {
  ntt_ct_std2rev(a, 16384, ntt16384_omega_powers_rev);
}

// inverse
static inline void intt16384_ct_rev2std(ap_int<260> *a) {
  ntt_ct_rev2std(a, 16384, ntt16384_inv_omega_powers);
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
extern void ntt16384_int_product(ap_int<260> *c, ap_int<260> *a, ap_int<260> *b);

#endif /* __ntt16384_H */
