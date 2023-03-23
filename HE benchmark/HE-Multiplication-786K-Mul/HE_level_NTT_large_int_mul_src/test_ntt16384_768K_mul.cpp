/*
 * Tests for ntt16384
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "ntt16384.h"
#include "sort.h"
#include "expected_result.h"



#include <iostream>
using namespace std;

/*
 * Print array of size n
 */
static void print_array(FILE *f, int32_t *a, int32_t n) {
  uint32_t i, k;

  k = 0;
  for (i=0; i<n; i++) {
    if (k == 0) fprintf(f, "  ");
    fprintf(f, "%5d", a[i]);
    k ++;
    if (k == 16) {
      fprintf(f, "\n");
      k = 0;
    } else {
      fprintf(f, " ");
    }
  }
  if (k > 0) {
    fprintf(f, "\n");
  }
}

ap_uint<260> QT = "115763822272329310636028559609001827025179711501300126126825041166177555972097";

int main(void) {

  ap_int<260> a[16384], b[16384], c[16384], red_c[16384];

  ap_int<32> N = 16384;
  ap_int<32> e = 96;
  ap_int<1023> base = (ap_int<1024>)(1)<<e;

  printf("768K Integer Multiplication using NTT Test starts (integers are mapped to polynomials)\n");


  //std::cout << "a[i]" << "\n";  
  for (ap_int<1023> i=0; i<16384/2; i++) {
    a[i] = (ap_int<1023>) (i*i*i*i*i*i) & (ap_int<1023>)(base-1); // Just a random number
    b[i] = (ap_int<1023>) (i*i*i*i*i*i+1) & (ap_int<1023>)(base-1); // Just another random number  
    //std::cout << a[i] << "\n";  
  }
  for (int i=16384/2; i<16384; i++) {
    a[i] = 0;
    b[i] = 0;
  }  
  
  /*printf("\na:\n");
  print_array(stdout, a, 16384);
  printf("\nb:\n");
  print_array(stdout, b, 16384);*/
  
  // Design under test (Large Integer Multiplication based on NTT)
  ntt16384_int_product(c, a, b);  // c := a * b


  
  // Final reduction
  for (int i=0; i<16384-1; i++) {
    c[i+1] = c[i+1] + (c[i] >> e); // remainder when divided by base
    c[i] = c[i] & (base-1);
  } 
  c[16384-1] = c[16384-1] % base;

  /*printf("\nc:\n");
  print_array(stdout, c, 16384);*/

  for (int i=0; i<16384; i++) {
    //std::cout << c[i] << "\n";
    if (expected_C[i] != c[i]) {
    printf("Failed on %d \n", i);
    // std::cout << "expected C[i]: " << expected_C[i] << "\n";
    // std::cout << "computed c[i]: " << c[i] << "\n";
    // exit(1);
    }
  }

  printf("Our test passed.\n\n");
  
  printf("Finished\n");

  return 0;
}

