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

    ap_uint<4096> modulus = ap_uint<4096>(
        "0xbdf1e5609329d2ec516cffe7f3c5a2b772363c746a6b8b7ffece3a91cd197d3441a9373122d66336f87802926500048f31c755addb054d293a918ca9064d3e497f7a6c1d6b3abd5366041f963a9517ad7b1786571a594856cd7bb70edc204275bd441aa833b41b112b8c81688e8d3f21569fb74f3bc940a85cb05eb4c9530fcb540f44d4e372f9e9f080b3c3d1810885804404f73d506374675fc87fa0792e0f65eb1a961d766d733cbb898d415d40e8497ce4e2e1a9f4cfaf2a98ab7705516ce7db0b1f87150a327f85aa71bbcf0fe27b7c9658a6fe875842af02370fcb5ba7b9d1c7b39ace7715a8766de7cecbd55e805f887065cb6d3f4b0a7072dade81694732d805ac321ffe6fde8d769941fa1bff6c78f9d419c8c817f533177062bea303203836b97eaa978f47706df72141afa24478d3b59c675c071f2d3e4fab4741965a135abdccb2daea58b25709499f5d2853dc061060eaf280aa60e4dff3fdabb5fe1dc93f1ed89f8cbda07fae669f75f607d9b231197cbada7803b2bb333bed75b3909ec5c93734ce78bd5552a2d97991efcee7a6eb31f78d5a6ff74079c13fc80037116279c7228c8301a75f1aecc6f51ed25ed7e25285408c3fe214f8ab2c5c02c9d5d33b54f2eb0f1425956dad95067040f049a1e148d0064db69f3238be69ff26acb60757087a859de2faf19a1562f5061e6e3eb31ae2070b87f38fd527");
         
    ap_uint<4096> message = 0;
    // unsigned char resm[256];
    unsigned char rawm[512] =
        "RSA TEST FILE : "
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
        "wxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefgh"
        "ijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRST"
"UVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890ABCDEF"
"GHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz12345678.";
    for (int i = 0; i < 511; i++) {
        message.range(i * 8 + 7, i * 8) = (unsigned int)rawm[512 - i];
    }
    message.range(7, 0) = ap_uint<8>("0x0a");

    ap_uint<20> exponent = ap_uint<20>("0x10001");
    ap_uint<20> exponent1 = ap_uint<20>("0x0001");

    ap_uint<4096> golden = ap_uint<4096>(
        "0xb01204aab2b651ec44d48a4e23b8248b3cc8094508e771221ee1b3771b61778a1fec5d87a5e44b8664e294f93121ca0664136da52335c6d6d5557fa283e11f1d873e6b84a14cd08f200d8f3b69271c3af6002f5c9d2c95c7602dc0ececcf24992755187a5e427d3872aea236d91d351a662782909d6ea8228fcfeb8c4ad68d2f763b44d37de1b7ba32260ac2b5f953980abf571956ae49fbca55d0b912a6c202fee4cebdb854019abdc5392615884e8a45d35d333cdbf7d57d493c8234fdcc484d390346686780b50dbe59e27e8e13ab40571748acefa5b3c3b74c3e65e281c57e4c5a80804dc9d24d66800baffb346859cdbb5364cd30cbdbf82134b9ea6451cf00e9988b0d0a486df4255b449a2b1d364abe634ca0a3285b019f25de5107fa478ccabb2809f0dc933440c9a8cbba78a8f70bc160d32ad6b641effaa0606bf8d5b9c59f9f7e07306f49e56c0baab03f43967235e8a5766d568e32dfc3fd79e9e2aff68aecb468f63dadf5b17b6cca031c3dc9fed9bd8816da91c23f28c39516955c23b0fe44c17ab762821dd355d0be134f75598f2b70bdb140e430a6fd9b82a1676dbcbe721feaa12296361ff9adad04b3b1ca934336d76f98ba1bd885d589016ee4e411556a9c3f3a8797d89f681520a3fb2e5c3cb85617ad20d18f022100e65c1bd998aa9d00886d1b72fbeb0f55d7867598f9fc1050a8eddf5cd39576f1");
    ap_uint<4096> golden1 = ap_uint<4096>(
        "0x4120544553542046494c45203a204142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a313233343536373839304142434445464748494a4b4c4d4e4f505152535455565758595a6162636465666768696a6b6c6d6e6f707172737475767778797a31323334353637382e000a");


    ap_uint<4096> mPrime = ap_uint<4096>( "0x988a403eceaa07ab21e7695181cf5679930d5918393261f1a147b1ac77d25a40c93150ae16d3fee00cec5f20cd17a47e31564e9e9ee70a686da37a0f5a46e3fab17cb2c0882a6bb85bf08eb38e1f4cd426e2b58598fc4e930e02b828eedf11f0dbb8cd18a43855e4eb47791768db7e282b0c6441f8f7538a7488642a0d8402f3e756b47c63cbc2ee7cca2edec024241498c8409bca448c57f3790595be89ea052b5882a214b99df1ac9e1b9c8d63080b683e1169f040a593b01f203d683fc948de79c5e9bf5293d2d7d6b3c855b8dc9fe74883d1507478e85e561fc8f6d4f1a73063f5976e451299bd91e6828b19c200127056d4b39a5a4c846142ffe9527cdc4e719ae50c1ccf573253f23f7c701622d53f5c82effa4d99e75a291b125ae830767ad0f14a00735878cff35720e896504a23f76d146e23e0dce69f108b9282fec7a9144222b234be70ea73ca32f1be7a182fde96b769c32eeda7d971b0386a18c41ecb80543e531172c307a8c3475ba849f6a01b84d995d9a80d24cc384eb0486f77e5d9ec1ed5cab0c6e9e3facd75a309fcf34b886921fb8a4626e27d4debe9f244092e86a1efc2d72778d9ceaa9c6c7113ac2a25939a5cba99384927dcfcb2dd8b7e16b1f0ac480c42482d0e37148604d394a4585b142bc32e0f8ba5818ac9cf4d8de32f5b0214750509afa2aedf4677ea7148ec1a8c535d25019fc76bb569");


    // get test result
    ap_uint<4096> result;

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

