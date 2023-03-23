// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xntt8192_int_product.h"

extern XNtt8192_int_product_Config XNtt8192_int_product_ConfigTable[];

XNtt8192_int_product_Config *XNtt8192_int_product_LookupConfig(u16 DeviceId) {
	XNtt8192_int_product_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XNTT8192_INT_PRODUCT_NUM_INSTANCES; Index++) {
		if (XNtt8192_int_product_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XNtt8192_int_product_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XNtt8192_int_product_Initialize(XNtt8192_int_product *InstancePtr, u16 DeviceId) {
	XNtt8192_int_product_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XNtt8192_int_product_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XNtt8192_int_product_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

