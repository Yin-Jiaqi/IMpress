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

    ap_uint<2048> modulus = ap_uint<2048>(
        "0x96d0a2172cdfce6dd1bedd1d9ec96d3471c89ae75188928bb2455a56ee20e3a7f82b08970e76a348ecd436d90bec1f161a4eb8671d91876bed7321cd2d976a1fed488077174d6f6bce45905c6a65625aa3dfba6b99386558cfd3929aa523f5273ab654c4f8a152accf746ea53812946633bee4a9ba2caf0809bead98f23cc9d27064c666c805c34460b54b95e798e35640e12808ba9f36e788a7ca2916c11ff19da4f2d3e79aa3e8ed8da4d02ed718e706a5b9e083ad6b0347447210a167f31531c65b58ae51bcdf2e5bd5e758a7995c845e57fca8dc531a489766030332373116dd3fdb023a6622eeb596898c8225b8d44b0ebb9081e99f7411ed3bb492fcb1");
         
    ap_uint<2048> message = 0;
    // unsigned char resm[256];
    unsigned char rawm[256] =
        "RSA TEST FILE : "
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
        "wxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefgh"
        "ijklmnopqrstuvwxyz.";
    for (int i = 0; i < 255; i++) {
        message.range(i * 8 + 7, i * 8) = (unsigned int)rawm[256 - i];
    }
    message.range(7, 0) = ap_uint<8>("0x0a");

    ap_uint<20> exponent = ap_uint<20>("0x10001");
    ap_uint<20> exponent1 = ap_uint<20>("0x0001");

    ap_uint<2048> golden = ap_uint<2048>(
        "0x6c102f792978b2e1194a3031807e1e5f65c217e09e4f7e100569b94d647f61ae1640ce12591655a883b6a5eb77aef7c755e53012245f217251748d4b927fee4e94f118ec502bb36076f662e2b650f843ed1c13dcacbe0bda65b6a4c6f32277aa9d8693686227bf700d9539ca0227c1a9c3859ab64e111bd5dac4b67ca788bb109f88bcaeadf1f18cebb1dffda031324b1df61c98c98c16eef872c7393004b7a39df551c465968ec96123375559007ead61174824f6ffb99c964345b60b8d1c21c109eaefe483d1699d9c0ca3270ab4ea11f2c52de21582008c9f66ba499d5c3e0bf961a07ac4f7065be87d86ad6a74f1edc458df9fe72331b559258f0640db97");
    ap_uint<2048> golden1 = ap_uint<2048>(
        "0x4120544553542046494c45203a204142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a2e000a");


    ap_uint<2048> mPrime = ap_uint<2048>( "0x7a044d16c211defc091f258788e7da1cb2988e4cd32e661288635a7b8661f8d54d66bfd68fa69c162aa9c65b00cdab0ec144123f64f3a1732268dfe518746049adc7b44d25b91ee042611a7c7e95cd70a8a69f48a52c8233f5c49a82922e871b496e7bb6547eb52f537170ae16369ff77d92ea1b8f4fdc0e3f3b3eaa94c5adcb4446954640913c5d7fca639725455852975d805fa6273a8b8640ff8529862346c7c5b85ab87f2fc5bda78cfff6b6e4245ea6cd560bc1e7bdb5ed26e09f8083fa5c34fa7046f0b10dcafe8e6b8227d87f3b65d989590a237b65aaaadb16d8020deaad422149db52d6da6be564c00936a577e44a183cbeb9fe6d718332d8e33af");


    // get test result
    ap_uint<2048> result;

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

