/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 *
 * @file modular.hpp
 * @brief header file for modular operators.
 * This file is part of Vitis Security Library.
 *
 */

#ifndef _XF_SECURITY_MODULAR_HPP_
#define _XF_SECURITY_MODULAR_HPP_
#include "mul1024_1_level_karatsuba.cpp"

#include <ap_int.h>
#include <hls_stream.h>


#ifndef __SYNTHESIS__
#include <iostream>
#endif

const unsigned int RSA_SIZE=1024;
const unsigned int RADIX=256; // RSA_SIZE should be divisible by RADIX
const unsigned int ND=RSA_SIZE/RADIX;

namespace xf {
namespace security {
namespace internal {

/*
 * @brief Montgomery Production of opA and opB and returns opA * opB * opM^-1 mod R
 * Reference: "Efficient architectures for implementing montgomery modular multiplication and RSA modular exponentiation
 * on reconfigurable logic" by Alan Daly, William Marnane
 *
 * @tparam N bit width of opA, opB and opM
 *
 * @param opA Montgomery representation of A
 * @param opB Montgomery representation of B
 * @param opM modulus
 */
template <int N>
ap_uint<N> monProduct_orig(ap_uint<N> opA, ap_uint<N> opB, ap_uint<N> opM) {
    ap_uint<N + 2> s = 0;
    ap_uint<1> a0 = opA[0];
    for (int i = 0; i < N; i++) {
        ap_uint<1> qa = opB[i];
        ap_uint<1> qm = s[0] ^ (opB[i] & a0);
        ap_uint<N> addA = qa == ap_uint<1>(1) ? opA : ap_uint<N>(0);
        ap_uint<N> addM = qm == ap_uint<1>(1) ? opM : ap_uint<N>(0);
        s += (addA + addM);
        s >>= 1;
    }
    if (s > opM) {
        s -= opM;
    }
    return s;
}

// Digit-based multiplication starts here

// multiplication
template <int RADIX>
void digit_multiplication(ap_uint<RADIX> x, ap_uint<RADIX> y, ap_uint<RADIX> *MSD, ap_uint<RADIX> *LSD){
    ap_uint<2*RADIX> result = xf::security::internal::mul::top<RADIX>(x, y);
    *LSD = result;
    *MSD = result >> RADIX;

}

template <int RADIX>
void multiplication(ap_uint<RADIX> *z, ap_uint<RADIX> *x, ap_uint<RADIX> *y){
#pragma HLS ALLOCATION operation instances=mul limit=3
    int i, j;
    for(i=0; i<2*ND; i++){
        z[i] = 0;
    }
    for(i=0; i<ND; i++){
        ap_uint<2*RADIX> carry = 0;
        for(j=0; j<ND; j++){
            int accum_i = i + j;
            ap_uint<RADIX> lo, hi;
            digit_multiplication(x[i], y[j], &hi, &lo);
            ap_uint<2*RADIX> accum  = z[accum_i] + carry + lo;
            carry                   = (accum >> RADIX) + hi;
            z[accum_i]              = accum;
        }
        z[i + ND] = carry;
    }
}

template <int RADIX>
void multiplication_only_low_order_digits(ap_uint<RADIX> *z, ap_uint<RADIX> *x, ap_uint<RADIX> *y){
#pragma HLS ALLOCATION operation instances=mul limit=3
    int i, j;
    for(i=0; i<ND; i++){
        z[i] = 0;
    }
    for(i=0; i<ND; i++){
        ap_uint<2*RADIX> carry = 0;
        for(j=0; j<ND; j++){
            int idx = i + j;
            if(idx<ND){
                ap_uint<RADIX> lo, hi;
                digit_multiplication(x[i], y[j], &hi, &lo);
                ap_uint<2*RADIX> accum  = z[idx] + carry + lo;
                carry                   = (accum >> RADIX) + hi;
                z[idx]                  = accum;
            }
        }
    }
}

template <int RADIX>
ap_uint<RADIX> addition(int count, ap_uint<RADIX> *res, ap_uint<RADIX> *x, ap_uint<RADIX> *y){
    int i;
    ap_uint<RADIX> carry = 0;
    for(i=0; i<count; i++){
        res[i]                 = x[i] + y[i];
        ap_uint<RADIX> carry1  = res[i] < x[i];
        res[i]                += carry;
        ap_uint<RADIX> carry2  = res[i] < carry;
        carry                  = carry1 | carry2;
    }
    return carry;
}

template <int RADIX>
ap_uint<RADIX> subtraction(int count, ap_uint<RADIX> *res, ap_uint<RADIX> *x, ap_uint<RADIX> *y){
    int i;
    ap_uint<RADIX> carry = 0;
    for(i=0; i<count; i++){
        ap_uint<RADIX> temp    = x[i] - y[i];
        ap_uint<RADIX> carry1  = temp > x[i];
        res[i]                 = temp - carry;
        ap_uint<RADIX> carry2  = res[i] > temp;
        carry                  = carry1 | carry2;
    }
    return carry;
}

template <int RADIX>
ap_uint<RADIX> less_than_or_equal(int count, ap_uint<RADIX> *x, ap_uint<RADIX> *y){
    int i;
    for(i=count - 1; i>=0; i--){
        if(x[i]>y[i]) return 0;
        if(x[i]<y[i]) return 1;
    }
    return 1;
}


template <int RADIX>
void mmul(ap_uint<RADIX> *res, ap_uint<RADIX> *x, ap_uint<RADIX> *y, ap_uint<RADIX> *m, ap_uint<RADIX> *mprime){
    ap_uint<RADIX> t[2*ND], tm[ND], tmm[2*ND], u[2*ND];

    int i;
    multiplication(t, x, y);

    multiplication_only_low_order_digits(tm, t, mprime);
    multiplication(tmm, tm, m);
    ap_uint<RADIX> carry = addition(2*ND, u, t, tmm);

    for(i=0; i<ND; i++){
        res[i] = u[i+ND];
    }
    if(carry>0 || less_than_or_equal(ND, m, res)){
        subtraction(ND, res, res, m);
    }
}


template <int N>
ap_uint<N> monProduct(ap_uint<N> opA, ap_uint<N> opB, ap_uint<N> opM, ap_uint<N> opMprime) {

    
    ap_uint<RADIX> res[ND];
    ap_uint<RADIX> x[ND];
    ap_uint<RADIX> y[ND];
    ap_uint<RADIX> m[ND];
    ap_uint<RADIX> mprime[ND];

    for(int i=0;i<ND;i++){
      x[i] = opA((i+1)*RADIX-1,i*RADIX);
      y[i] = opB((i+1)*RADIX-1,i*RADIX);
      m[i] = opM((i+1)*RADIX-1,i*RADIX);
      mprime[i] = opMprime((i+1)*RADIX-1,i*RADIX);
    }

    mmul<RADIX>(res, x, y, m, mprime);    

    ap_uint<N> uPrime;
    for(int i=0;i<ND;i++){
      uPrime((i+1)*RADIX-1,i*RADIX) = res[i];
    }
    return (ap_uint<N>)uPrime;
}


template <int N>
ap_uint<N> monProduct_expanded(ap_uint<N> opA, ap_uint<N> opB, ap_uint<N> opM, ap_uint<N> opMprime) {


//std::cout << "\n###### MonPro starts ###### " << "\n" << std::endl;
//std::cout << "\nopA: " << opA << "\n" << std::endl;
//std::cout << "\nopB: " << opB << "\n" << std::endl;

    // large multiplication that can be partitioned into lower-digit multiplications
    ap_uint<2*N> t = opA * opB;

//std::cout << "\nt: " << t << "\n" << std::endl;

    ap_uint<3*N> m = t * opMprime;

    ap_uint<N> m_red = m & (((ap_uint<N+1>)1<<N)-1);

//std::cout << "\nm: " << m << "\n" << std::endl;

    ap_uint<N+1> uPrime = ((ap_uint<2*N+1>)(t+m_red*opM))>>N;

//std::cout << "\nuPrime: " << uPrime << "\n" << std::endl;
   
    if (uPrime >= opM) {
        uPrime -= opM;
    }

//std::cout << "\n###### MonPro ends ###### " << "\n" << std::endl;

    return (ap_uint<N>)uPrime;
}

/*
 * @brief Modular Exponentiation
 *
 * @tparam L bit width of base and modulus
 * @tparam N bit width of exponent
 *
 * @param base Base of Modular Exponentiation
 * @param exponent Exponent of Modular Exponentiation
 * @param modulus Modulus of Modular Exponentiation
 * @param rMod 2^(2*L) mod modulus could be pre-calculated.
 */
template <int L, int N>
ap_uint<L> modularExp(ap_uint<L> base, ap_uint<N> exponent, ap_uint<L> modulus, ap_uint<L> mPrime, ap_uint<L> rMod) {

   /*std::cout << "rMod: " << rMod << std::endl;
   std::cout << "base: " << base << std::endl;
   std::cout << "modulus: " << modulus << std::endl;*/

    ap_uint<L> P = monProduct<L>(rMod, base, modulus, mPrime);

    //std::cout << "P result: " << P << std::endl;

    ap_uint<L> R = monProduct<L>(rMod, 1, modulus, mPrime);
    for (int i = N - 1; i >= 0; i--) {
        R = monProduct<L>(R, R, modulus, mPrime);
        if (exponent[i] == 1) {
            R = monProduct<L>(R, P, modulus, mPrime);
        }
    }
    return monProduct<L>(R, 1, modulus, mPrime);
}

/*
 * @brief modulo operation, returns remainder of dividend against divisor.
 *
 * @tparam L bit width of dividend
 * @tparam N bit width of divisor
 *
 * @param dividend Dividend
 * @param divisor Divisor
 */
template <int L, int N>
ap_uint<N> simpleMod(ap_uint<L> dividend, ap_uint<N> divisor) {
    ap_uint<N> remainder = dividend % divisor;
    return remainder;
}

/**
 * @brief return (opA * opB) mod opM
 *
 * @tparam N bit width of opA, opB and opM
 *
 * @param opA Product input, should be less than opM
 * @param opB Product input, should be less than opM
 * @param opM Modulus, should be larger than 2^(N-1)
 */
template <int N>
ap_uint<N> productMod(ap_uint<N> opA, ap_uint<N> opB, ap_uint<N> opM) {
    ap_uint<N + 1> tmp = 0;
    for (int i = N - 1; i >= 0; i--) {
        tmp <<= 1;
        if (tmp >= opM) {
            tmp -= opM;
        }
        if (opB[i] == 1) {
            tmp += opA;
            if (tmp >= opM) {
                tmp -= opM;
            }
        }
    }
    return tmp;
}

/**
 * @brief return (opA + opB) mod opM
 *
 * @tparam N bit width of opA, opB and opM
 *
 * @param opA Product input, should be less than opM
 * @param opB Product input, should be less than opM
 * @param opM Modulus
 */
template <int N>
ap_uint<N> addMod(ap_uint<N> opA, ap_uint<N> opB, ap_uint<N> opM) {
    ap_uint<N + 1> sum = opA + opB;
    if (sum >= opM) {
        sum -= opM;
    }
    return sum;
}

/**
 * @brief return (opA - opB) mod opM
 *
 * @tparam N bit width of opA, opB and opM
 *
 * @param opA Product input, should be less than opM
 * @param opB Product input, should be less than opM
 * @param opM Modulus
 */
template <int N>
ap_uint<N> subMod(ap_uint<N> opA, ap_uint<N> opB, ap_uint<N> opM) {
    ap_uint<N + 1> sum;
    if (opA >= opB) {
        sum = opA - opB;
    } else {
        sum = opA + opM;
        sum -= opB;
    }
    return sum;
}

/**
 * @brief return montgomery inverse of opA
 * Reference: "The Montgomery Modular Inverse - Revisited" by E Savas, CK Koç
 *
 * @tparam N bit width of opA and opM
 *
 * @param opA Input of modular inverse.
 * @param opM Modulus of modular inverse.
 */
template <int N>
ap_uint<N> monInv(ap_uint<N> opA, ap_uint<N> opM) {
    // calc r = opA^-1 * 2^k and k
    ap_uint<N> u = opM;
    ap_uint<N> v = opA;
    ap_uint<N> s = 1;
    ap_uint<N + 1> r = 0;
    ap_uint<32> k = 0;

    while (v > 0) {
        if (u[0] == 0) {
            u >>= 1;
            s <<= 1;
        } else if (v[0] == 0) {
            v >>= 1;
            r <<= 1;
        } else if (u > v) {
            u -= v;
            u >>= 1;
            r += s;
            s <<= 1;
        } else {
            v -= u;
            v >>= 1;
            s += r;
            r <<= 1;
        }
        k++;
    }

    if (r >= opM) {
        r -= opM;
    }
    r = opM - r;

    k -= N;

    for (int i = 0; i < k; i++) {
        if (r[0] == 1) {
            r += opM;
        }
        r >>= 1;
    }

    return r;
}

/**
 * @brief return modular inverse of opA
 * Reference: "The Montgomery Modular Inverse - Revisited" by E Savas, CK Koç
 *
 * @tparam N bit width of opA and opM, opM should no less than 2^(N-1)
 *
 * @param opA Input of modular inverse. opA should be non-zero, might need extra checking
 * @param opM Modulus of modular inverse.
 */
template <int N>
ap_uint<N> modularInv(ap_uint<N> opA, ap_uint<N> opM) {
    // calc r = opA^-1 * 2^k and k
    ap_uint<N> u = opM;
    ap_uint<N> v = opA;
    ap_uint<N> s = 1;
    ap_uint<N + 1> r = 0;
    ap_uint<32> k = 0;

    while (v > 0) {
        if (u[0] == 0) {
            u >>= 1;
            s <<= 1;
        } else if (v[0] == 0) {
            v >>= 1;
            r <<= 1;
        } else if (u > v) {
            u -= v;
            u >>= 1;
            r += s;
            s <<= 1;
        } else {
            v -= u;
            v >>= 1;
            s += r;
            r <<= 1;
        }
        k++;
    }

    if (r >= opM) {
        r -= opM;
    }
    r = opM - r;

    k -= N;

    for (int i = 0; i < k; i++) {
        if (r[0] == 1) {
            r += opM;
        }
        r >>= 1;
    }

    ap_uint<N> res = monProduct<N>(r.range(N - 1, 0), 1, opM);

    return res;
}

} // namespace internal
} // namespace security
} // namespace xf

#endif
