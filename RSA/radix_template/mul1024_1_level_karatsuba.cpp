#include "ap_int.h"

namespace xf {
namespace security {
namespace internal {
namespace mul {

template <int RADIX>
ap_uint<2*512> PP_0_default(ap_uint<512> in0, ap_uint<512> in1) {
    #pragma HLS inline

    ap_uint<2*512> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*513> PP_1_default(ap_uint<513> in0, ap_uint<513> in1) {
    #pragma HLS inline

    ap_uint<2*513> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*512> PP_2_default(ap_uint<512> in0, ap_uint<512> in1) {
    #pragma HLS inline

    ap_uint<2*512> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*1024> top(ap_uint<1024> in0, ap_uint<1024> in1) {
    #pragma HLS inline

    ap_uint<1024/2> in0_up = in0 >> (1024/2);
    ap_uint<1024/2> in0_low = (in0 << (1024/2)) >> (1024/2);
    ap_uint<1024/2> in1_up = in1 >> (1024/2);
    ap_uint<1024/2> in1_low = (in1 << (1024/2)) >> (1024/2);

    ap_uint<1024> m0 = PP_0_default<RADIX>(in0_low, in1_low);
    ap_uint<1024> m1 = PP_2_default<RADIX>(in0_up, in1_up);
    ap_uint<1024/2+1> sa = in0_low + in0_up;
    ap_uint<1024/2+1> sb = in1_low + in1_up;
    ap_uint<1024+2> m2 = PP_1_default<RADIX>(sa, sb);
    ap_uint<1024+1> t0 = m0 + m1;
    ap_uint<1024+2> t1 = m2 - t0;

    ap_uint<2*1024> out = ((ap_uint<1024 + 1024>)m1 << 1024) + ((ap_uint<1024+2 + 1024/2>)t1 << (1024/2)) + m0;
    return out;

}

}
}
}
}

