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

#include <iostream>
#include "test.hpp"
#include <string>

int main() {
    std::cout << std::hex;

    ap_uint<512> modulus = ap_uint<512>(
        "0x9d41cd0d38339220ebd110e8c31feb279c5fae3c23090045a0886301588d4c8114fa5cdde708ea77ba0f527e6f6ea8f5634acf517f042113131321131313211");
         
    ap_uint<512> message = 0;
    // unsigned char resm[256];
    unsigned char rawm[64] =
        "RSA TEST FILE : "
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrst";
    for (int i = 0; i < 63; i++) {
        message.range(i * 8 + 7, i * 8) = (unsigned int)rawm[64 - i];
    }
    message.range(7, 0) = ap_uint<8>("0x0a");

    ap_uint<20> exponent = ap_uint<20>("0x10001");
    ap_uint<20> exponent1 = ap_uint<20>("0x0001");

    ap_uint<512> golden = ap_uint<512>(
        "0x72e5197491b489915737220e45e46d1a125ead3dc90231a2919c4cd91ff2f0e2b774d8a4206552c64febab1078aa6d870abfa78b2b94d5d0f8fc9e427519ad1");
    ap_uint<512> golden1 = ap_uint<512>(
        "0x4120544553542046494c45203a204142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737400000a");


    ap_uint<512> mPrime = ap_uint<512>( "0xc8287149f7b2de1496cbda34d63bf2d1078d3b601b9d032f7ff267f829f0eac9efe5301de76d34a29c039631472f283990e15183ee493be2b5c16581322c010f");


    // get test result
    ap_uint<512> result;

    /*message = ap_uint<2048>("2");
    exponent = ap_uint<2048>("5");
    modulus = ap_uint<2048>("0xb");*/

    std::cout << "message     : " << message << std::endl;
    std::cout << "modulus     : " << modulus << std::endl;
    std::cout << "my exponent : " << exponent << std::endl;

    rsa_test(message, modulus, exponent, mPrime, result);

    std::cout << "my result    : " << result << std::endl;

    if (result != golden) {
        std::cout << "Not Match !!!" << std::endl;
        std::cout << "My result     : " << result << std::endl;
        std::cout << "Correct result: " << golden << std::endl;
        return 1;
    }else{
        std::cout << "Test is SUCCESSFUL !!!" << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

