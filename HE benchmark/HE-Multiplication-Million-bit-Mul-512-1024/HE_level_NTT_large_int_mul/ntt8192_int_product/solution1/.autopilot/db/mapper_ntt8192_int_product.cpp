#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
struct __cosim_s40__ { char data[64]; };
extern "C" void ntt8192_int_product(__cosim_s40__*, int, int, int);
extern "C" void apatb_ntt8192_int_product_hw(volatile void * __xlx_apatb_param_c, volatile void * __xlx_apatb_param_a, volatile void * __xlx_apatb_param_b) {
  // Collect __xlx_c_a_b__tmp_vec
  vector<sc_bv<512> >__xlx_c_a_b__tmp_vec;
  for (int j = 0, e = 8192; j != e; ++j) {
    sc_bv<512> _xlx_tmp_sc;
    _xlx_tmp_sc.range(63, 0) = ((long long*)__xlx_apatb_param_c)[j*8+0];
    _xlx_tmp_sc.range(127, 64) = ((long long*)__xlx_apatb_param_c)[j*8+1];
    _xlx_tmp_sc.range(191, 128) = ((long long*)__xlx_apatb_param_c)[j*8+2];
    _xlx_tmp_sc.range(255, 192) = ((long long*)__xlx_apatb_param_c)[j*8+3];
    _xlx_tmp_sc.range(319, 256) = ((long long*)__xlx_apatb_param_c)[j*8+4];
    _xlx_tmp_sc.range(383, 320) = ((long long*)__xlx_apatb_param_c)[j*8+5];
    _xlx_tmp_sc.range(447, 384) = ((long long*)__xlx_apatb_param_c)[j*8+6];
    _xlx_tmp_sc.range(511, 448) = ((long long*)__xlx_apatb_param_c)[j*8+7];
    __xlx_c_a_b__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_c = 8192;
  int __xlx_offset_param_c = 0;
  int __xlx_offset_byte_param_c = 0*64;
  for (int j = 0, e = 8192; j != e; ++j) {
    sc_bv<512> _xlx_tmp_sc;
    _xlx_tmp_sc.range(63, 0) = ((long long*)__xlx_apatb_param_a)[j*8+0];
    _xlx_tmp_sc.range(127, 64) = ((long long*)__xlx_apatb_param_a)[j*8+1];
    _xlx_tmp_sc.range(191, 128) = ((long long*)__xlx_apatb_param_a)[j*8+2];
    _xlx_tmp_sc.range(255, 192) = ((long long*)__xlx_apatb_param_a)[j*8+3];
    _xlx_tmp_sc.range(319, 256) = ((long long*)__xlx_apatb_param_a)[j*8+4];
    _xlx_tmp_sc.range(383, 320) = ((long long*)__xlx_apatb_param_a)[j*8+5];
    _xlx_tmp_sc.range(447, 384) = ((long long*)__xlx_apatb_param_a)[j*8+6];
    _xlx_tmp_sc.range(511, 448) = ((long long*)__xlx_apatb_param_a)[j*8+7];
    __xlx_c_a_b__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_a = 8192;
  int __xlx_offset_param_a = 8192;
  int __xlx_offset_byte_param_a = 8192*64;
  for (int j = 0, e = 8192; j != e; ++j) {
    sc_bv<512> _xlx_tmp_sc;
    _xlx_tmp_sc.range(63, 0) = ((long long*)__xlx_apatb_param_b)[j*8+0];
    _xlx_tmp_sc.range(127, 64) = ((long long*)__xlx_apatb_param_b)[j*8+1];
    _xlx_tmp_sc.range(191, 128) = ((long long*)__xlx_apatb_param_b)[j*8+2];
    _xlx_tmp_sc.range(255, 192) = ((long long*)__xlx_apatb_param_b)[j*8+3];
    _xlx_tmp_sc.range(319, 256) = ((long long*)__xlx_apatb_param_b)[j*8+4];
    _xlx_tmp_sc.range(383, 320) = ((long long*)__xlx_apatb_param_b)[j*8+5];
    _xlx_tmp_sc.range(447, 384) = ((long long*)__xlx_apatb_param_b)[j*8+6];
    _xlx_tmp_sc.range(511, 448) = ((long long*)__xlx_apatb_param_b)[j*8+7];
    __xlx_c_a_b__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_b = 8192;
  int __xlx_offset_param_b = 16384;
  int __xlx_offset_byte_param_b = 16384*64;
  __cosim_s40__* __xlx_c_a_b__input_buffer= new __cosim_s40__[__xlx_c_a_b__tmp_vec.size()];
  for (int i = 0; i < __xlx_c_a_b__tmp_vec.size(); ++i) {
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+0] = __xlx_c_a_b__tmp_vec[i].range(63, 0).to_uint64();
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+1] = __xlx_c_a_b__tmp_vec[i].range(127, 64).to_uint64();
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+2] = __xlx_c_a_b__tmp_vec[i].range(191, 128).to_uint64();
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+3] = __xlx_c_a_b__tmp_vec[i].range(255, 192).to_uint64();
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+4] = __xlx_c_a_b__tmp_vec[i].range(319, 256).to_uint64();
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+5] = __xlx_c_a_b__tmp_vec[i].range(383, 320).to_uint64();
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+6] = __xlx_c_a_b__tmp_vec[i].range(447, 384).to_uint64();
    ((long long*)__xlx_c_a_b__input_buffer)[i*8+7] = __xlx_c_a_b__tmp_vec[i].range(511, 448).to_uint64();
  }
  // DUT call
  ntt8192_int_product(__xlx_c_a_b__input_buffer, __xlx_offset_byte_param_c, __xlx_offset_byte_param_a, __xlx_offset_byte_param_b);
// print __xlx_apatb_param_c
  sc_bv<512>*__xlx_c_output_buffer = new sc_bv<512>[__xlx_size_param_c];
  for (int i = 0; i < __xlx_size_param_c; ++i) {
    char* start = (char*)(&(__xlx_c_a_b__input_buffer[__xlx_offset_param_c]));
    __xlx_c_output_buffer[i].range(63, 0) = ((long long*)start)[i*8+0];
    __xlx_c_output_buffer[i].range(127, 64) = ((long long*)start)[i*8+1];
    __xlx_c_output_buffer[i].range(191, 128) = ((long long*)start)[i*8+2];
    __xlx_c_output_buffer[i].range(255, 192) = ((long long*)start)[i*8+3];
    __xlx_c_output_buffer[i].range(319, 256) = ((long long*)start)[i*8+4];
    __xlx_c_output_buffer[i].range(383, 320) = ((long long*)start)[i*8+5];
    __xlx_c_output_buffer[i].range(447, 384) = ((long long*)start)[i*8+6];
    __xlx_c_output_buffer[i].range(511, 448) = ((long long*)start)[i*8+7];
  }
  for (int i = 0; i < __xlx_size_param_c; ++i) {
    ((long long*)__xlx_apatb_param_c)[i*8+0] = __xlx_c_output_buffer[i].range(63, 0).to_uint64();
    ((long long*)__xlx_apatb_param_c)[i*8+1] = __xlx_c_output_buffer[i].range(127, 64).to_uint64();
    ((long long*)__xlx_apatb_param_c)[i*8+2] = __xlx_c_output_buffer[i].range(191, 128).to_uint64();
    ((long long*)__xlx_apatb_param_c)[i*8+3] = __xlx_c_output_buffer[i].range(255, 192).to_uint64();
    ((long long*)__xlx_apatb_param_c)[i*8+4] = __xlx_c_output_buffer[i].range(319, 256).to_uint64();
    ((long long*)__xlx_apatb_param_c)[i*8+5] = __xlx_c_output_buffer[i].range(383, 320).to_uint64();
    ((long long*)__xlx_apatb_param_c)[i*8+6] = __xlx_c_output_buffer[i].range(447, 384).to_uint64();
    ((long long*)__xlx_apatb_param_c)[i*8+7] = __xlx_c_output_buffer[i].range(511, 448).to_uint64();
  }
// print __xlx_apatb_param_a
  sc_bv<512>*__xlx_a_output_buffer = new sc_bv<512>[__xlx_size_param_a];
  for (int i = 0; i < __xlx_size_param_a; ++i) {
    char* start = (char*)(&(__xlx_c_a_b__input_buffer[__xlx_offset_param_a]));
    __xlx_a_output_buffer[i].range(63, 0) = ((long long*)start)[i*8+0];
    __xlx_a_output_buffer[i].range(127, 64) = ((long long*)start)[i*8+1];
    __xlx_a_output_buffer[i].range(191, 128) = ((long long*)start)[i*8+2];
    __xlx_a_output_buffer[i].range(255, 192) = ((long long*)start)[i*8+3];
    __xlx_a_output_buffer[i].range(319, 256) = ((long long*)start)[i*8+4];
    __xlx_a_output_buffer[i].range(383, 320) = ((long long*)start)[i*8+5];
    __xlx_a_output_buffer[i].range(447, 384) = ((long long*)start)[i*8+6];
    __xlx_a_output_buffer[i].range(511, 448) = ((long long*)start)[i*8+7];
  }
  for (int i = 0; i < __xlx_size_param_a; ++i) {
    ((long long*)__xlx_apatb_param_a)[i*8+0] = __xlx_a_output_buffer[i].range(63, 0).to_uint64();
    ((long long*)__xlx_apatb_param_a)[i*8+1] = __xlx_a_output_buffer[i].range(127, 64).to_uint64();
    ((long long*)__xlx_apatb_param_a)[i*8+2] = __xlx_a_output_buffer[i].range(191, 128).to_uint64();
    ((long long*)__xlx_apatb_param_a)[i*8+3] = __xlx_a_output_buffer[i].range(255, 192).to_uint64();
    ((long long*)__xlx_apatb_param_a)[i*8+4] = __xlx_a_output_buffer[i].range(319, 256).to_uint64();
    ((long long*)__xlx_apatb_param_a)[i*8+5] = __xlx_a_output_buffer[i].range(383, 320).to_uint64();
    ((long long*)__xlx_apatb_param_a)[i*8+6] = __xlx_a_output_buffer[i].range(447, 384).to_uint64();
    ((long long*)__xlx_apatb_param_a)[i*8+7] = __xlx_a_output_buffer[i].range(511, 448).to_uint64();
  }
// print __xlx_apatb_param_b
  sc_bv<512>*__xlx_b_output_buffer = new sc_bv<512>[__xlx_size_param_b];
  for (int i = 0; i < __xlx_size_param_b; ++i) {
    char* start = (char*)(&(__xlx_c_a_b__input_buffer[__xlx_offset_param_b]));
    __xlx_b_output_buffer[i].range(63, 0) = ((long long*)start)[i*8+0];
    __xlx_b_output_buffer[i].range(127, 64) = ((long long*)start)[i*8+1];
    __xlx_b_output_buffer[i].range(191, 128) = ((long long*)start)[i*8+2];
    __xlx_b_output_buffer[i].range(255, 192) = ((long long*)start)[i*8+3];
    __xlx_b_output_buffer[i].range(319, 256) = ((long long*)start)[i*8+4];
    __xlx_b_output_buffer[i].range(383, 320) = ((long long*)start)[i*8+5];
    __xlx_b_output_buffer[i].range(447, 384) = ((long long*)start)[i*8+6];
    __xlx_b_output_buffer[i].range(511, 448) = ((long long*)start)[i*8+7];
  }
  for (int i = 0; i < __xlx_size_param_b; ++i) {
    ((long long*)__xlx_apatb_param_b)[i*8+0] = __xlx_b_output_buffer[i].range(63, 0).to_uint64();
    ((long long*)__xlx_apatb_param_b)[i*8+1] = __xlx_b_output_buffer[i].range(127, 64).to_uint64();
    ((long long*)__xlx_apatb_param_b)[i*8+2] = __xlx_b_output_buffer[i].range(191, 128).to_uint64();
    ((long long*)__xlx_apatb_param_b)[i*8+3] = __xlx_b_output_buffer[i].range(255, 192).to_uint64();
    ((long long*)__xlx_apatb_param_b)[i*8+4] = __xlx_b_output_buffer[i].range(319, 256).to_uint64();
    ((long long*)__xlx_apatb_param_b)[i*8+5] = __xlx_b_output_buffer[i].range(383, 320).to_uint64();
    ((long long*)__xlx_apatb_param_b)[i*8+6] = __xlx_b_output_buffer[i].range(447, 384).to_uint64();
    ((long long*)__xlx_apatb_param_b)[i*8+7] = __xlx_b_output_buffer[i].range(511, 448).to_uint64();
  }
}
