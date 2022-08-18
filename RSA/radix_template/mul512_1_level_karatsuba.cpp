#include "ap_int.h"

namespace xf {
namespace security {
namespace internal {
namespace mul {

template <int RADIX>
ap_uint<2*256> PP_0_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*257> PP_1_default(ap_uint<257> in0, ap_uint<257> in1) {
    #pragma HLS inline

    ap_uint<2*257> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*256> PP_2_default(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<2*256> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*512> top(ap_uint<512> in0, ap_uint<512> in1) {
    #pragma HLS inline

    ap_uint<512/2> in0_up = in0 >> (512/2);
    ap_uint<512/2> in0_low = (in0 << (512/2)) >> (512/2);
    ap_uint<512/2> in1_up = in1 >> (512/2);
    ap_uint<512/2> in1_low = (in1 << (512/2)) >> (512/2);

    ap_uint<512> m0 = PP_0_default<RADIX>(in0_low, in1_low);
    ap_uint<512> m1 = PP_2_default<RADIX>(in0_up, in1_up);
    ap_uint<512/2+1> sa = in0_low + in0_up;
    ap_uint<512/2+1> sb = in1_low + in1_up;
    ap_uint<512+2> m2 = PP_1_default<RADIX>(sa, sb);
    ap_uint<512+1> t0 = m0 + m1;
    ap_uint<512+2> t1 = m2 - t0;

    ap_uint<2*512> out = ((ap_uint<512 + 512>)m1 << 512) + ((ap_uint<512+2 + 512/2>)t1 << (512/2)) + m0;
    return out;

}

}
}
}
}