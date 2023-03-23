/*
 * NTT for Q and n=8192.
 */

#include "ntt8192.h"
#include <stdint.h>

#include <ap_int.h>

#include <iostream>
using namespace std;

/*
 * Print array of size n
 */
static void print_array(FILE *f, ap_int<512> *a, int32_t n) {
  uint32_t i, k;

  k = 0;
  for (i=0; i<n; i++) {
    if (k == 0) fprintf(f, "  ");
    //fprintf(f, "%5"PRIu32, a[i]);
    std::cout << a[i] << "\n"; //", ";
    k ++;
    /*if (k == 16) {
      fprintf(f, "\n");
      k = 0;
    } else {
      fprintf(f, " ");
    }*/
  }
  if (k > 0) {
    fprintf(f, "\n");
  }
}

/*
 * Product of two polynomials
 */
void ntt8192_int_product(ap_int<512> c[8192], ap_int<512> a[8192], ap_int<512> b[8192]) {
#pragma HLS INTERFACE s_axilite port=a 
#pragma HLS INTERFACE s_axilite port=b 
#pragma HLS INTERFACE m_axi port=c offset=slave 

//#pragma HLS PIPELINE II=1

  //mul_array16(a, 8192, ntt8192_psi_powers);
  //printf("iso\n");

  //std::cout << "a_in[8192]=\n";
  //print_array(stdout, a, 8192);
  ntt8192_ct_std2rev(a);
     ////bitrev_shuffle(a,8192); // uncomment this when needed in debug
  //std::cout << "a_ntt[8192]=\n";
  //print_array(stdout, a, 8192);
  ////mul_array16(b, 8192, ntt8192_psi_powers);

  //std::cout << "b_in[8192]=\n";
  //print_array(stdout, b, 8192);
  ntt8192_ct_std2rev(b);
  //std::cout << "b_ntt[8192]=\n";
  //print_array(stdout, b, 8192);

  mul_array(c, 8192, a, b);
  //bitrev_shuffle(c,n);
  //std::cout << "mul_c[8192]=\n";
  //print_array(stdout, c, 8192);

  intt8192_ct_rev2std(c);
  ////mul_array16(c, 8192, ntt8192_scaled_inv_psi_powers);
  scalar_mul_array(c, 8192, ntt8192_inv_n); // divide by n
  //std::cout << "res[8192]=\n";
  //print_array(stdout, c, 8192);
}

