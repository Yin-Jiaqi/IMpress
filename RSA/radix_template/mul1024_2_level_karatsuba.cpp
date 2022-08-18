#include "ap_int.h"

namespace xf {
namespace security {
namespace internal {
namespace mul {

template <int RADIX>
ap_uint<2*256> PP_0_0_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*257> PP_0_1_default(ap_uint<257> in0, ap_uint<257> in1) {
    #pragma HLS inline

    ap_uint<2*257> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*256> PP_0_2_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*512> PP_0_karatsuba(ap_uint<512> in0, ap_uint<512> in1) {
    #pragma HLS inline

    ap_uint<512/2> in0_up = in0 >> (512/2);
    ap_uint<512/2> in0_low = (in0 << (512/2)) >> (512/2);
    ap_uint<512/2> in1_up = in1 >> (512/2);
    ap_uint<512/2> in1_low = (in1 << (512/2)) >> (512/2);

    ap_uint<512> m0 = PP_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<512> m1 = PP_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<512/2+1> sa = in0_low + in0_up;
    ap_uint<512/2+1> sb = in1_low + in1_up;
    ap_uint<512+2> m2 = PP_0_1_default<RADIX>(sa, sb);
    ap_uint<512+1> t0 = m0 + m1;
    ap_uint<512+2> t1 = m2 - t0;

    ap_uint<2*512> out = ((ap_uint<512 + 512>)m1 << 512) + ((ap_uint<512+2 + 512/2>)t1 << (512/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*256> PP_1_0_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*257> PP_1_1_default(ap_uint<257> in0, ap_uint<257> in1) {
    #pragma HLS inline

    ap_uint<2*257> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*256> PP_1_2_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*513> PP_1_karatsuba_odd(ap_uint<513> in0, ap_uint<513> in1) {
    #pragma HLS inline

    ap_uint<513-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (513-1)) >> (513-1);
    ap_uint<513-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (513-1)) >> (513-1);

    ap_uint<513-1> pp_up_low = i0_up * i1_low;
    ap_uint<513-1> pp_low_up = i0_low * i1_up;
    ap_uint<1> pp_low_low = i0_low * i1_low;

    ap_uint<(513-1)/2> in0_up = i0_up >> ((513-1)/2);
    ap_uint<(513-1)/2> in0_low = (i0_up << ((513-1)/2)) >> ((513-1)/2);
    ap_uint<(513-1)/2> in1_up = i1_up >> ((513-1)/2);
    ap_uint<(513-1)/2> in1_low = (i1_up << ((513-1)/2)) >> ((513-1)/2);
    ap_uint<513-1> m0 = PP_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<513-1> m1 = PP_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(513+1)/2> sa = in0_low + in0_up;
    ap_uint<(513+1)/2> sb = in1_low + in1_up;
    ap_uint<513+1> m2 = PP_1_1_default<RADIX>(sa, sb);
    ap_uint<513> t0 = m0 + m1;
    ap_uint<513+1> t1 = m2 - t0;
    ap_uint<2*(513-1)> pp_up_up = ((ap_uint<513-1 + 513-1>)m1 << (513-1)) + ((ap_uint<513+1 + (513-1)/2>)t1 << ((513-1)/2)) + m0; 

    ap_uint<2*513> out = ((ap_uint<2*513>)pp_up_up << 2) + ((ap_uint<513>)pp_up_low << 1) + ((ap_uint<513>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*256> PP_2_0_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*257> PP_2_1_default(ap_uint<257> in0, ap_uint<257> in1) {
    #pragma HLS inline

    ap_uint<2*257> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*256> PP_2_2_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*512> PP_2_karatsuba(ap_uint<512> in0, ap_uint<512> in1) {
    #pragma HLS inline

    ap_uint<512/2> in0_up = in0 >> (512/2);
    ap_uint<512/2> in0_low = (in0 << (512/2)) >> (512/2);
    ap_uint<512/2> in1_up = in1 >> (512/2);
    ap_uint<512/2> in1_low = (in1 << (512/2)) >> (512/2);

    ap_uint<512> m0 = PP_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<512> m1 = PP_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<512/2+1> sa = in0_low + in0_up;
    ap_uint<512/2+1> sb = in1_low + in1_up;
    ap_uint<512+2> m2 = PP_2_1_default<RADIX>(sa, sb);
    ap_uint<512+1> t0 = m0 + m1;
    ap_uint<512+2> t1 = m2 - t0;

    ap_uint<2*512> out = ((ap_uint<512 + 512>)m1 << 512) + ((ap_uint<512+2 + 512/2>)t1 << (512/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*1024> top(ap_uint<1024> in0, ap_uint<1024> in1) {
    #pragma HLS inline

    ap_uint<1024/2> in0_up = in0 >> (1024/2);
    ap_uint<1024/2> in0_low = (in0 << (1024/2)) >> (1024/2);
    ap_uint<1024/2> in1_up = in1 >> (1024/2);
    ap_uint<1024/2> in1_low = (in1 << (1024/2)) >> (1024/2);

    ap_uint<1024> m0 = PP_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<1024> m1 = PP_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<1024/2+1> sa = in0_low + in0_up;
    ap_uint<1024/2+1> sb = in1_low + in1_up;
    ap_uint<1024+2> m2 = PP_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<1024+1> t0 = m0 + m1;
    ap_uint<1024+2> t1 = m2 - t0;

    ap_uint<2*1024> out = ((ap_uint<1024 + 1024>)m1 << 1024) + ((ap_uint<1024+2 + 1024/2>)t1 << (1024/2)) + m0;
    return out;

}

}
}
}
}