// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xntt8192_int_product.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XNtt8192_int_product_CfgInitialize(XNtt8192_int_product *InstancePtr, XNtt8192_int_product_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XNtt8192_int_product_Start(XNtt8192_int_product *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL) & 0x80;
    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XNtt8192_int_product_IsDone(XNtt8192_int_product *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XNtt8192_int_product_IsIdle(XNtt8192_int_product *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XNtt8192_int_product_IsReady(XNtt8192_int_product *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XNtt8192_int_product_Continue(XNtt8192_int_product *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL) & 0x80;
    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL, Data | 0x10);
}

void XNtt8192_int_product_EnableAutoRestart(XNtt8192_int_product *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XNtt8192_int_product_DisableAutoRestart(XNtt8192_int_product *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_AP_CTRL, 0);
}

void XNtt8192_int_product_Set_c(XNtt8192_int_product *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_C_DATA, (u32)(Data));
    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_C_DATA + 4, (u32)(Data >> 32));
}

u64 XNtt8192_int_product_Get_c(XNtt8192_int_product *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_C_DATA);
    Data += (u64)XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_C_DATA + 4) << 32;
    return Data;
}

void XNtt8192_int_product_Set_a(XNtt8192_int_product *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_A_DATA, (u32)(Data));
    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_A_DATA + 4, (u32)(Data >> 32));
}

u64 XNtt8192_int_product_Get_a(XNtt8192_int_product *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_A_DATA);
    Data += (u64)XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_A_DATA + 4) << 32;
    return Data;
}

void XNtt8192_int_product_Set_b(XNtt8192_int_product *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_B_DATA, (u32)(Data));
    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_B_DATA + 4, (u32)(Data >> 32));
}

u64 XNtt8192_int_product_Get_b(XNtt8192_int_product *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_B_DATA);
    Data += (u64)XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_B_DATA + 4) << 32;
    return Data;
}

void XNtt8192_int_product_InterruptGlobalEnable(XNtt8192_int_product *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_GIE, 1);
}

void XNtt8192_int_product_InterruptGlobalDisable(XNtt8192_int_product *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_GIE, 0);
}

void XNtt8192_int_product_InterruptEnable(XNtt8192_int_product *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_IER);
    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_IER, Register | Mask);
}

void XNtt8192_int_product_InterruptDisable(XNtt8192_int_product *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_IER);
    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_IER, Register & (~Mask));
}

void XNtt8192_int_product_InterruptClear(XNtt8192_int_product *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNtt8192_int_product_WriteReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_ISR, Mask);
}

u32 XNtt8192_int_product_InterruptGetEnabled(XNtt8192_int_product *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_IER);
}

u32 XNtt8192_int_product_InterruptGetStatus(XNtt8192_int_product *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNtt8192_int_product_ReadReg(InstancePtr->Control_BaseAddress, XNTT8192_INT_PRODUCT_CONTROL_ADDR_ISR);
}

