// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XNTT8192_INT_PRODUCT_H
#define XNTT8192_INT_PRODUCT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xntt8192_int_product_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XNtt8192_int_product_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XNtt8192_int_product;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XNtt8192_int_product_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XNtt8192_int_product_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XNtt8192_int_product_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XNtt8192_int_product_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XNtt8192_int_product_Initialize(XNtt8192_int_product *InstancePtr, u16 DeviceId);
XNtt8192_int_product_Config* XNtt8192_int_product_LookupConfig(u16 DeviceId);
int XNtt8192_int_product_CfgInitialize(XNtt8192_int_product *InstancePtr, XNtt8192_int_product_Config *ConfigPtr);
#else
int XNtt8192_int_product_Initialize(XNtt8192_int_product *InstancePtr, const char* InstanceName);
int XNtt8192_int_product_Release(XNtt8192_int_product *InstancePtr);
#endif

void XNtt8192_int_product_Start(XNtt8192_int_product *InstancePtr);
u32 XNtt8192_int_product_IsDone(XNtt8192_int_product *InstancePtr);
u32 XNtt8192_int_product_IsIdle(XNtt8192_int_product *InstancePtr);
u32 XNtt8192_int_product_IsReady(XNtt8192_int_product *InstancePtr);
void XNtt8192_int_product_Continue(XNtt8192_int_product *InstancePtr);
void XNtt8192_int_product_EnableAutoRestart(XNtt8192_int_product *InstancePtr);
void XNtt8192_int_product_DisableAutoRestart(XNtt8192_int_product *InstancePtr);

void XNtt8192_int_product_Set_c(XNtt8192_int_product *InstancePtr, u64 Data);
u64 XNtt8192_int_product_Get_c(XNtt8192_int_product *InstancePtr);
void XNtt8192_int_product_Set_a(XNtt8192_int_product *InstancePtr, u64 Data);
u64 XNtt8192_int_product_Get_a(XNtt8192_int_product *InstancePtr);
void XNtt8192_int_product_Set_b(XNtt8192_int_product *InstancePtr, u64 Data);
u64 XNtt8192_int_product_Get_b(XNtt8192_int_product *InstancePtr);

void XNtt8192_int_product_InterruptGlobalEnable(XNtt8192_int_product *InstancePtr);
void XNtt8192_int_product_InterruptGlobalDisable(XNtt8192_int_product *InstancePtr);
void XNtt8192_int_product_InterruptEnable(XNtt8192_int_product *InstancePtr, u32 Mask);
void XNtt8192_int_product_InterruptDisable(XNtt8192_int_product *InstancePtr, u32 Mask);
void XNtt8192_int_product_InterruptClear(XNtt8192_int_product *InstancePtr, u32 Mask);
u32 XNtt8192_int_product_InterruptGetEnabled(XNtt8192_int_product *InstancePtr);
u32 XNtt8192_int_product_InterruptGetStatus(XNtt8192_int_product *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
