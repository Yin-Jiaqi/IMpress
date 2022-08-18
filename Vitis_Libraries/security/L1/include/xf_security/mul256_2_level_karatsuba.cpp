#include "ap_int.h"

namespace xf {
namespace security {
namespace internal {
namespace mul {

template <int RADIX>
ap_uint<2*64> PP_0_0_default(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<2*64> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*65> PP_0_1_default(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<2*65> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*64> PP_0_2_default(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<2*64> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_0_1_default<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*64> PP_1_0_default(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<2*64> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*65> PP_1_1_default(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<2*65> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*64> PP_1_2_default(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<2*64> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
    #pragma HLS inline

    ap_uint<129-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (129-1)) >> (129-1);
    ap_uint<129-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (129-1)) >> (129-1);

    ap_uint<129-1> pp_up_low = i0_up * i1_low;
    ap_uint<129-1> pp_low_up = i0_low * i1_up;
    ap_uint<1> pp_low_low = i0_low * i1_low;

    ap_uint<(129-1)/2> in0_up = i0_up >> ((129-1)/2);
    ap_uint<(129-1)/2> in0_low = (i0_up << ((129-1)/2)) >> ((129-1)/2);
    ap_uint<(129-1)/2> in1_up = i1_up >> ((129-1)/2);
    ap_uint<(129-1)/2> in1_low = (i1_up << ((129-1)/2)) >> ((129-1)/2);
    ap_uint<129-1> m0 = PP_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_1_1_default<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*64> PP_2_0_default(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<2*64> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*65> PP_2_1_default(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<2*65> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*64> PP_2_2_default(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<2*64> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_2_1_default<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*256> top(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<256> m1 = PP_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
    return out;

}

}
}
}
}