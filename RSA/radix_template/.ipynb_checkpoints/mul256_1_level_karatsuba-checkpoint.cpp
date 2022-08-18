#include "ap_int.h"


ap_uint<2*128> PP_0_default(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<2*128> out = in0 * in1;
    return out;

}


ap_uint<2*129> PP_1_default(ap_uint<129> in0, ap_uint<129> in1) {
    #pragma HLS inline

    ap_uint<2*129> out = in0 * in1;
    return out;

}


ap_uint<2*128> PP_2_default(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<2*128> out = in0 * in1;
    return out;

}



ap_uint<2*256> top(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_0_default(in0_low, in1_low);
    ap_uint<256> m1 = PP_2_default(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_1_default(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
    return out;

}

