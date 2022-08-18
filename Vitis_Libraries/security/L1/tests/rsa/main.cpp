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

    ap_uint<1024> modulus = ap_uint<1024>(
        "0xe9b1e63ea705250440eaec5eb1f40f36d5677c5d52d21c941c9816fac17f9eee67e655fbc569a188a09d486c6b3865cafe3f328682fcca5bf19b35af548656ecd5521f472d6af877d474c8d54be66a33bec3c70b41dcf165617921691d4c8e164642b6e33f2afa57b4b34e3d7300b4522472c97d84b12aff4e5d30920531532d");
         
    ap_uint<1024> message = 0;
    // unsigned char resm[256];
    unsigned char rawm[128] =
        "RSA TEST FILE : "
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
        "i";
    for (int i = 0; i < 127; i++) {
        message.range(i * 8 + 7, i * 8) = (unsigned int)rawm[128 - i];
    }
    message.range(7, 0) = ap_uint<8>("0x0a");

    ap_uint<20> exponent = ap_uint<20>("0x10001");
    ap_uint<20> exponent1 = ap_uint<20>("0x0001");

    ap_uint<1024> golden = ap_uint<1024>(
        "0x95e6f837ba46e837cdec40a72b30979ca2e018ef2adc675c0946e0e39c6962637b77cfb5bfe21363f9531c2c2f1821a0534e602b2651ae54026a5f48f91cf0495bf2a8e5d91c02439700369e723a52ba5cc48e13d7e1f50b567f9c69c6db0558b1e1e4d487ef69a28f8109e77bbcb4171a32098c8081e80b7b281dec8488e24f");
    ap_uint<1024> golden1 = ap_uint<1024>(
        "0x4120544553542046494c45203a204142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f7071727374757669000a");


    ap_uint<1024> mPrime = ap_uint<1024>( "0x5169313be22a63357015cf8cfde61220b306c4e6e0b8de4a0329262898fdb5f6e75e4316b6e2533e3506d330f1c78736df3573a3cd026fe0f00099d1a6deb769efc70738871d2a4c40938e13aefc00f3fdeb77bc49d73bf7e3f89965ba2b09bd7e2844c262506dfb9996bc3a44637fb871a4025ed5da95c3f37abae8c5468b5b");


    // get test result
    ap_uint<1024> result;

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
