# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__HLS_FPO_v6_1__ = 1

__SIM_MATHHLS__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = ../../../../../HE_level_NTT_large_int_mul_src/sort.cpp ../../../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp ../../../../../HE_level_NTT_large_int_mul_src/ntt8192_tables.cpp ../../../../../HE_level_NTT_large_int_mul_src/ntt.cpp ../../../../../HE_level_NTT_large_int_mul_src/ntt8192.cpp

override TARGET := csim.exe

AUTOPILOT_ROOT := /media/asyam/bce327c2-015d-448b-a5ee-db0952816570/opt/Vitis_HLS/2020.2
AUTOPILOT_MACH := lnx64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
IFLAG += -fPIC
ifndef AP_GCC_PATH
  AP_GCC_PATH := /media/asyam/bce327c2-015d-448b-a5ee-db0952816570/opt/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_TOOL}/clang-3.9/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -I "/usr/include/x86_64-linux-gnu"
IFLAG += -D__VITIS_HLS__

IFLAG += -D__SIM_FPO__

IFLAG += -D__HLS_FPO_v6_1__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E2__
IFLAG += -Wno-unknown-pragmas 
IFLAG += -g
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += -Werror=return-type
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



$(ObjDir)/sort.o: ../../../../../HE_level_NTT_large_int_mul_src/sort.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../../HE_level_NTT_large_int_mul_src/sort.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/sort.d

$(ObjDir)/test_ntt8192_1M_mul.o: ../../../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../../HE_level_NTT_large_int_mul_src/test_ntt8192_1M_mul.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/test_ntt8192_1M_mul.d

$(ObjDir)/ntt8192_tables.o: ../../../../../HE_level_NTT_large_int_mul_src/ntt8192_tables.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../../HE_level_NTT_large_int_mul_src/ntt8192_tables.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/ntt8192_tables.d

$(ObjDir)/ntt.o: ../../../../../HE_level_NTT_large_int_mul_src/ntt.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../../HE_level_NTT_large_int_mul_src/ntt.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/ntt.d

$(ObjDir)/ntt8192.o: ../../../../../HE_level_NTT_large_int_mul_src/ntt8192.cpp $(ObjDir)/.dir
	$(Echo) "   Compiling ../../../../../HE_level_NTT_large_int_mul_src/ntt8192.cpp in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(CC) ${CCFLAG} -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/ntt8192.d
