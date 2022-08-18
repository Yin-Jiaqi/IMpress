#include "ap_int.h"

namespace xf {
namespace security {
namespace internal {
namespace mul {

template <int RADIX>
ap_uint<2*16> PP_0_0_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_0_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_0_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_0_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_0_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_0_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_0_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_0_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_0_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_0_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_0_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_0_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_0_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_0_0_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_0_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_0_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_0_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_0_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_0_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_0_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_0_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_0_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_0_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_0_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_0_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_0_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_0_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_0_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_0_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_0_0_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_0_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_0_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_0_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_0_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_0_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_0_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_0_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_0_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_0_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_0_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_0_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_0_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_0_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_0_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_0_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_0_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_0_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_0_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_0_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_0_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_0_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_0_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_0_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_0_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_0_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_0_0_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_0_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_0_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_0_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*256> PP_0_0_karatsuba(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<256> m1 = PP_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_1_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_1_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_1_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_1_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_1_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_1_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_1_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_1_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_1_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_1_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_1_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_1_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_0_1_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_0_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_0_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_0_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_1_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_1_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_1_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_1_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_1_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_1_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_1_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_1_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_1_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_1_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_1_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_1_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_0_1_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_0_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_0_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_0_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_1_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_1_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_1_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_1_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_1_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_1_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_1_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_1_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_1_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_1_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_1_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_1_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_1_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_1_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_1_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_1_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_1_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_1_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_1_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_1_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_1_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_1_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_0_1_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_0_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_0_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_0_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*257> PP_0_1_karatsuba_odd(ap_uint<257> in0, ap_uint<257> in1) {
    #pragma HLS inline

    ap_uint<257-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (257-1)) >> (257-1);
    ap_uint<257-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (257-1)) >> (257-1);

    ap_uint<257-1> pp_up_low = i0_up * i1_low; 
    ap_uint<257-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(257-1)/2> in0_up = i0_up >> ((257-1)/2);
    ap_uint<(257-1)/2> in0_low = (i0_up << ((257-1)/2)) >> ((257-1)/2);
    ap_uint<(257-1)/2> in1_up = i1_up >> ((257-1)/2);
    ap_uint<(257-1)/2> in1_low = (i1_up << ((257-1)/2)) >> ((257-1)/2);
    ap_uint<257-1> m0 = PP_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<257-1> m1 = PP_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(257+1)/2> sa = in0_low + in0_up;
    ap_uint<(257+1)/2> sb = in1_low + in1_up;
    ap_uint<257+1> m2 = PP_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<257> t0 = m0 + m1;
    ap_uint<257+1> t1 = m2 - t0;
    ap_uint<2*(257-1)> pp_up_up = ((ap_uint<257-1 + 257-1>)m1 << (257-1)) + ((ap_uint<257+1 + (257-1)/2>)t1 << ((257-1)/2)) + m0; 

    ap_uint<2*257> out = ((ap_uint<2*257>)pp_up_up << 2) + ((ap_uint<257>)pp_up_low << 1) + ((ap_uint<257>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_2_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_2_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_2_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_2_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_2_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_2_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_2_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_2_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_2_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_2_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_2_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_2_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_0_2_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_0_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_0_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_0_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_2_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_2_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_2_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_2_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_2_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_2_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_2_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_2_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_2_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_2_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_2_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_2_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_0_2_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_0_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_0_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_0_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_2_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_2_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_2_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_2_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_0_2_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_0_2_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_0_2_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_0_2_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_0_2_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_0_2_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_0_2_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_0_2_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_0_2_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_0_2_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_0_2_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_0_2_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_0_2_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_0_2_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_0_2_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_0_2_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_0_2_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_0_2_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_0_2_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_0_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_0_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_0_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*256> PP_0_2_karatsuba(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<256> m1 = PP_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*512> PP_0_karatsuba(ap_uint<512> in0, ap_uint<512> in1) {
    #pragma HLS inline

    ap_uint<512/2> in0_up = in0 >> (512/2);
    ap_uint<512/2> in0_low = (in0 << (512/2)) >> (512/2);
    ap_uint<512/2> in1_up = in1 >> (512/2);
    ap_uint<512/2> in1_low = (in1 << (512/2)) >> (512/2);

    ap_uint<512> m0 = PP_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<512> m1 = PP_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<512/2+1> sa = in0_low + in0_up;
    ap_uint<512/2+1> sb = in1_low + in1_up;
    ap_uint<512+2> m2 = PP_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<512+1> t0 = m0 + m1;
    ap_uint<512+2> t1 = m2 - t0;

    ap_uint<2*512> out = ((ap_uint<512 + 512>)m1 << 512) + ((ap_uint<512+2 + 512/2>)t1 << (512/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_0_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_0_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_0_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_0_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_0_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_0_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_0_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_0_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_0_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_0_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_0_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_0_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_1_0_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_1_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_1_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_1_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_0_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_0_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_0_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_0_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_0_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_0_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_0_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_0_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_0_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_0_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_0_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_0_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_1_0_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_1_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_1_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_1_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_0_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_0_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_0_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_0_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_0_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_0_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_0_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_0_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_0_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_0_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_0_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_0_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_0_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_0_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_0_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_0_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_0_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_0_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_0_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_0_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_0_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_0_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_1_0_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_1_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_1_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_1_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*256> PP_1_0_karatsuba(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<256> m1 = PP_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_1_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_1_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_1_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_1_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_1_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_1_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_1_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_1_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_1_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_1_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_1_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_1_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_1_1_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_1_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_1_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_1_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_1_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_1_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_1_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_1_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_1_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_1_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_1_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_1_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_1_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_1_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_1_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_1_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_1_1_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_1_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_1_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_1_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_1_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_1_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_1_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_1_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_1_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_1_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_1_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_1_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_1_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_1_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_1_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_1_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_1_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_1_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_1_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_1_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_1_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_1_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_1_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_1_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_1_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_1_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_1_1_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_1_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_1_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_1_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*257> PP_1_1_karatsuba_odd(ap_uint<257> in0, ap_uint<257> in1) {
    #pragma HLS inline

    ap_uint<257-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (257-1)) >> (257-1);
    ap_uint<257-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (257-1)) >> (257-1);

    ap_uint<257-1> pp_up_low = i0_up * i1_low; 
    ap_uint<257-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(257-1)/2> in0_up = i0_up >> ((257-1)/2);
    ap_uint<(257-1)/2> in0_low = (i0_up << ((257-1)/2)) >> ((257-1)/2);
    ap_uint<(257-1)/2> in1_up = i1_up >> ((257-1)/2);
    ap_uint<(257-1)/2> in1_low = (i1_up << ((257-1)/2)) >> ((257-1)/2);
    ap_uint<257-1> m0 = PP_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<257-1> m1 = PP_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(257+1)/2> sa = in0_low + in0_up;
    ap_uint<(257+1)/2> sb = in1_low + in1_up;
    ap_uint<257+1> m2 = PP_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<257> t0 = m0 + m1;
    ap_uint<257+1> t1 = m2 - t0;
    ap_uint<2*(257-1)> pp_up_up = ((ap_uint<257-1 + 257-1>)m1 << (257-1)) + ((ap_uint<257+1 + (257-1)/2>)t1 << ((257-1)/2)) + m0; 

    ap_uint<2*257> out = ((ap_uint<2*257>)pp_up_up << 2) + ((ap_uint<257>)pp_up_low << 1) + ((ap_uint<257>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_2_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_2_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_2_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_2_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_2_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_2_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_2_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_2_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_2_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_2_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_2_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_2_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_1_2_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_1_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_1_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_1_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_2_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_2_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_2_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_2_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_2_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_2_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_2_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_2_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_2_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_2_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_2_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_2_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_1_2_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_1_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_1_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_1_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_2_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_2_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_2_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_2_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_1_2_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_1_2_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_1_2_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_1_2_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_1_2_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_1_2_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_1_2_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_1_2_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_1_2_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_1_2_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_1_2_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_1_2_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_1_2_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_1_2_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_1_2_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_1_2_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_1_2_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_1_2_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_1_2_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_1_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_1_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_1_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*256> PP_1_2_karatsuba(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<256> m1 = PP_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
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
    ap_uint<513-1> m0 = PP_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<513-1> m1 = PP_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(513+1)/2> sa = in0_low + in0_up;
    ap_uint<(513+1)/2> sb = in1_low + in1_up;
    ap_uint<513+1> m2 = PP_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<513> t0 = m0 + m1;
    ap_uint<513+1> t1 = m2 - t0;
    ap_uint<2*(513-1)> pp_up_up = ((ap_uint<513-1 + 513-1>)m1 << (513-1)) + ((ap_uint<513+1 + (513-1)/2>)t1 << ((513-1)/2)) + m0; 

    ap_uint<2*513> out = ((ap_uint<2*513>)pp_up_up << 2) + ((ap_uint<513>)pp_up_low << 1) + ((ap_uint<513>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_0_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_0_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_0_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_0_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_0_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_0_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_0_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_0_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_0_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_0_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_0_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_0_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_2_0_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_2_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_2_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_2_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_0_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_0_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_0_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_0_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_0_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_0_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_0_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_0_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_0_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_0_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_0_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_0_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_2_0_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_2_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_2_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_2_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_0_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_0_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_0_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_0_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_0_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_0_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_0_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_0_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_0_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_0_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_0_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_0_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_0_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_0_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_0_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_0_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_0_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_0_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_0_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_0_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_0_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_0_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_2_0_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_2_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_2_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_2_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*256> PP_2_0_karatsuba(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<256> m1 = PP_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_1_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_1_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_1_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_1_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_1_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_1_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_1_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_1_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_1_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_1_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_1_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_1_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_2_1_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_2_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_2_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_2_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_1_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_1_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_1_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_1_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_1_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_1_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_1_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_1_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_1_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_1_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_1_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_1_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_2_1_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_2_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_2_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_2_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_1_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_1_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_1_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_1_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_1_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_1_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_1_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_1_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_1_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_1_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_1_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_1_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_1_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_1_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_1_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_1_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_1_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_1_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_1_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_1_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_1_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_1_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_2_1_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_2_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_2_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_2_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*257> PP_2_1_karatsuba_odd(ap_uint<257> in0, ap_uint<257> in1) {
    #pragma HLS inline

    ap_uint<257-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (257-1)) >> (257-1);
    ap_uint<257-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (257-1)) >> (257-1);

    ap_uint<257-1> pp_up_low = i0_up * i1_low; 
    ap_uint<257-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(257-1)/2> in0_up = i0_up >> ((257-1)/2);
    ap_uint<(257-1)/2> in0_low = (i0_up << ((257-1)/2)) >> ((257-1)/2);
    ap_uint<(257-1)/2> in1_up = i1_up >> ((257-1)/2);
    ap_uint<(257-1)/2> in1_low = (i1_up << ((257-1)/2)) >> ((257-1)/2);
    ap_uint<257-1> m0 = PP_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<257-1> m1 = PP_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(257+1)/2> sa = in0_low + in0_up;
    ap_uint<(257+1)/2> sb = in1_low + in1_up;
    ap_uint<257+1> m2 = PP_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<257> t0 = m0 + m1;
    ap_uint<257+1> t1 = m2 - t0;
    ap_uint<2*(257-1)> pp_up_up = ((ap_uint<257-1 + 257-1>)m1 << (257-1)) + ((ap_uint<257+1 + (257-1)/2>)t1 << ((257-1)/2)) + m0; 

    ap_uint<2*257> out = ((ap_uint<2*257>)pp_up_up << 2) + ((ap_uint<257>)pp_up_low << 1) + ((ap_uint<257>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_0_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_0_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_0_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_0_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_0_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_0_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_0_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_0_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_0_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_0_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_0_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_0_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_2_0_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_2_0_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_2_0_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_2_0_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_0_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_0_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_0_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_0_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_0_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_0_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_0_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_0_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_0_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_0_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_0_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_0_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_2_0_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_2_0_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_2_0_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_2_0_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_0_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_0_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_0_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_0_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_0_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_0_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_0_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_0_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_0_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_0_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_0_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_0_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_0_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_0_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_2_0_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_2_0_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_2_0_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_2_0_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_2_2_0_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_2_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_2_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_2_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_1_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_1_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_1_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_1_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_1_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_1_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_1_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_1_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_1_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_1_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_1_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_1_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_2_1_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_2_1_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_2_1_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_2_1_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_1_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_1_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_1_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_1_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_1_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_1_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_1_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_1_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_1_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_1_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_1_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_1_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_2_1_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_2_1_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_2_1_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_2_1_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_1_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_1_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_1_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_1_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_1_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_1_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_1_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_1_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_1_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_1_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_1_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_1_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_1_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_1_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_2_1_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_2_1_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_2_1_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_2_1_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*129> PP_2_2_1_karatsuba_odd(ap_uint<129> in0, ap_uint<129> in1) {
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
    ap_uint<129-1> m0 = PP_2_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<129-1> m1 = PP_2_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(129+1)/2> sa = in0_low + in0_up;
    ap_uint<(129+1)/2> sb = in1_low + in1_up;
    ap_uint<129+1> m2 = PP_2_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<129> t0 = m0 + m1;
    ap_uint<129+1> t1 = m2 - t0;
    ap_uint<2*(129-1)> pp_up_up = ((ap_uint<129-1 + 129-1>)m1 << (129-1)) + ((ap_uint<129+1 + (129-1)/2>)t1 << ((129-1)/2)) + m0; 

    ap_uint<2*129> out = ((ap_uint<2*129>)pp_up_up << 2) + ((ap_uint<129>)pp_up_low << 1) + ((ap_uint<129>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_0_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_0_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_0_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_2_0_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_2_0_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_2_0_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_2_0_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_0_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_0_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_0_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_2_0_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_2_0_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_2_0_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_2_0_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_0_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_0_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_0_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_2_0_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_2_0_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_2_0_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_2_0_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_2_2_0_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_2_2_0_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_2_2_0_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_2_2_0_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_1_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_1_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_1_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_2_1_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_2_1_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_2_1_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_2_1_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_1_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_1_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_1_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_2_1_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_2_1_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_2_1_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_2_1_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_1_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_1_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_1_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_2_1_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_2_1_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_2_1_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_2_1_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*65> PP_2_2_2_1_karatsuba_odd(ap_uint<65> in0, ap_uint<65> in1) {
    #pragma HLS inline

    ap_uint<65-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (65-1)) >> (65-1);
    ap_uint<65-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (65-1)) >> (65-1);

    ap_uint<65-1> pp_up_low = i0_up * i1_low; 
    ap_uint<65-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(65-1)/2> in0_up = i0_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in0_low = (i0_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_up = i1_up >> ((65-1)/2);
    ap_uint<(65-1)/2> in1_low = (i1_up << ((65-1)/2)) >> ((65-1)/2);
    ap_uint<65-1> m0 = PP_2_2_2_1_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<65-1> m1 = PP_2_2_2_1_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<(65+1)/2> sa = in0_low + in0_up;
    ap_uint<(65+1)/2> sb = in1_low + in1_up;
    ap_uint<65+1> m2 = PP_2_2_2_1_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<65> t0 = m0 + m1;
    ap_uint<65+1> t1 = m2 - t0;
    ap_uint<2*(65-1)> pp_up_up = ((ap_uint<65-1 + 65-1>)m1 << (65-1)) + ((ap_uint<65+1 + (65-1)/2>)t1 << ((65-1)/2)) + m0; 

    ap_uint<2*65> out = ((ap_uint<2*65>)pp_up_up << 2) + ((ap_uint<65>)pp_up_low << 1) + ((ap_uint<65>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_2_0_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_2_0_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_2_0_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_2_2_0_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_2_2_0_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_2_2_0_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_2_2_0_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_2_1_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_2_1_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_2_1_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*33> PP_2_2_2_2_1_karatsuba_odd(ap_uint<33> in0, ap_uint<33> in1) {
    #pragma HLS inline

    ap_uint<33-1> i0_up = in0 >> 1;
    ap_uint<1> i0_low = (in0 << (33-1)) >> (33-1);
    ap_uint<33-1> i1_up = in1 >> 1;
    ap_uint<1> i1_low = (in1 << (33-1)) >> (33-1);

    ap_uint<33-1> pp_up_low = i0_up * i1_low; 
    ap_uint<33-1> pp_low_up = i0_low * i1_up; 
    ap_uint<1> pp_low_low = i0_low * i1_low; 

    
    ap_uint<(33-1)/2> in0_up = i0_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in0_low = (i0_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_up = i1_up >> ((33-1)/2);
    ap_uint<(33-1)/2> in1_low = (i1_up << ((33-1)/2)) >> ((33-1)/2);
    ap_uint<33-1> m0 = PP_2_2_2_2_1_0_default<RADIX>(in0_low, in1_low);
    ap_uint<33-1> m1 = PP_2_2_2_2_1_2_default<RADIX>(in0_up, in1_up);
    ap_uint<(33+1)/2> sa = in0_low + in0_up;
    ap_uint<(33+1)/2> sb = in1_low + in1_up;
    ap_uint<33+1> m2 = PP_2_2_2_2_1_1_default<RADIX>(sa, sb);
    ap_uint<33> t0 = m0 + m1;
    ap_uint<33+1> t1 = m2 - t0;
    ap_uint<2*(33-1)> pp_up_up = ((ap_uint<33-1 + 33-1>)m1 << (33-1)) + ((ap_uint<33+1 + (33-1)/2>)t1 << ((33-1)/2)) + m0; 

    ap_uint<2*33> out = ((ap_uint<2*33>)pp_up_up << 2) + ((ap_uint<33>)pp_up_low << 1) + ((ap_uint<33>)pp_low_up << 1) + pp_low_low;

    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_2_2_0_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*17> PP_2_2_2_2_2_1_default(ap_uint<17> in0, ap_uint<17> in1) {
    #pragma HLS inline

    ap_uint<2*17> out = in0 * in1;
    return out;

}


template <int RADIX>
ap_uint<2*16> PP_2_2_2_2_2_2_default(ap_uint<16> in0, ap_uint<16> in1) {
    #pragma HLS inline

    ap_uint<2*16> out = in0 * in1;
    return out;

}



template <int RADIX>
ap_uint<2*32> PP_2_2_2_2_2_karatsuba(ap_uint<32> in0, ap_uint<32> in1) {
    #pragma HLS inline

    ap_uint<32/2> in0_up = in0 >> (32/2);
    ap_uint<32/2> in0_low = (in0 << (32/2)) >> (32/2);
    ap_uint<32/2> in1_up = in1 >> (32/2);
    ap_uint<32/2> in1_low = (in1 << (32/2)) >> (32/2);

    ap_uint<32> m0 = PP_2_2_2_2_2_0_default<RADIX>(in0_low, in1_low);
    ap_uint<32> m1 = PP_2_2_2_2_2_2_default<RADIX>(in0_up, in1_up);
    ap_uint<32/2+1> sa = in0_low + in0_up;
    ap_uint<32/2+1> sb = in1_low + in1_up;
    ap_uint<32+2> m2 = PP_2_2_2_2_2_1_default<RADIX>(sa, sb);
    ap_uint<32+1> t0 = m0 + m1;
    ap_uint<32+2> t1 = m2 - t0;

    ap_uint<2*32> out = ((ap_uint<32 + 32>)m1 << 32) + ((ap_uint<32+2 + 32/2>)t1 << (32/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*64> PP_2_2_2_2_karatsuba(ap_uint<64> in0, ap_uint<64> in1) {
    #pragma HLS inline

    ap_uint<64/2> in0_up = in0 >> (64/2);
    ap_uint<64/2> in0_low = (in0 << (64/2)) >> (64/2);
    ap_uint<64/2> in1_up = in1 >> (64/2);
    ap_uint<64/2> in1_low = (in1 << (64/2)) >> (64/2);

    ap_uint<64> m0 = PP_2_2_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<64> m1 = PP_2_2_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<64/2+1> sa = in0_low + in0_up;
    ap_uint<64/2+1> sb = in1_low + in1_up;
    ap_uint<64+2> m2 = PP_2_2_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<64+1> t0 = m0 + m1;
    ap_uint<64+2> t1 = m2 - t0;

    ap_uint<2*64> out = ((ap_uint<64 + 64>)m1 << 64) + ((ap_uint<64+2 + 64/2>)t1 << (64/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*128> PP_2_2_2_karatsuba(ap_uint<128> in0, ap_uint<128> in1) {
    #pragma HLS inline

    ap_uint<128/2> in0_up = in0 >> (128/2);
    ap_uint<128/2> in0_low = (in0 << (128/2)) >> (128/2);
    ap_uint<128/2> in1_up = in1 >> (128/2);
    ap_uint<128/2> in1_low = (in1 << (128/2)) >> (128/2);

    ap_uint<128> m0 = PP_2_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<128> m1 = PP_2_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<128/2+1> sa = in0_low + in0_up;
    ap_uint<128/2+1> sb = in1_low + in1_up;
    ap_uint<128+2> m2 = PP_2_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<128+1> t0 = m0 + m1;
    ap_uint<128+2> t1 = m2 - t0;

    ap_uint<2*128> out = ((ap_uint<128 + 128>)m1 << 128) + ((ap_uint<128+2 + 128/2>)t1 << (128/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*256> PP_2_2_karatsuba(ap_uint<256> in0, ap_uint<256> in1) {
    #pragma HLS inline

    ap_uint<256/2> in0_up = in0 >> (256/2);
    ap_uint<256/2> in0_low = (in0 << (256/2)) >> (256/2);
    ap_uint<256/2> in1_up = in1 >> (256/2);
    ap_uint<256/2> in1_low = (in1 << (256/2)) >> (256/2);

    ap_uint<256> m0 = PP_2_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<256> m1 = PP_2_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<256/2+1> sa = in0_low + in0_up;
    ap_uint<256/2+1> sb = in1_low + in1_up;
    ap_uint<256+2> m2 = PP_2_2_1_karatsuba_odd<RADIX>(sa, sb);
    ap_uint<256+1> t0 = m0 + m1;
    ap_uint<256+2> t1 = m2 - t0;

    ap_uint<2*256> out = ((ap_uint<256 + 256>)m1 << 256) + ((ap_uint<256+2 + 256/2>)t1 << (256/2)) + m0;
    return out;

}



template <int RADIX>
ap_uint<2*512> PP_2_karatsuba(ap_uint<512> in0, ap_uint<512> in1) {
    #pragma HLS inline

    ap_uint<512/2> in0_up = in0 >> (512/2);
    ap_uint<512/2> in0_low = (in0 << (512/2)) >> (512/2);
    ap_uint<512/2> in1_up = in1 >> (512/2);
    ap_uint<512/2> in1_low = (in1 << (512/2)) >> (512/2);

    ap_uint<512> m0 = PP_2_0_karatsuba<RADIX>(in0_low, in1_low);
    ap_uint<512> m1 = PP_2_2_karatsuba<RADIX>(in0_up, in1_up);
    ap_uint<512/2+1> sa = in0_low + in0_up;
    ap_uint<512/2+1> sb = in1_low + in1_up;
    ap_uint<512+2> m2 = PP_2_1_karatsuba_odd<RADIX>(sa, sb);
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