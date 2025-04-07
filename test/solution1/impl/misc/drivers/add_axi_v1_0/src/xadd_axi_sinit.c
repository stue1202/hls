// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xadd_axi.h"

extern XAdd_axi_Config XAdd_axi_ConfigTable[];

XAdd_axi_Config *XAdd_axi_LookupConfig(u16 DeviceId) {
	XAdd_axi_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XADD_AXI_NUM_INSTANCES; Index++) {
		if (XAdd_axi_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XAdd_axi_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAdd_axi_Initialize(XAdd_axi *InstancePtr, u16 DeviceId) {
	XAdd_axi_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAdd_axi_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAdd_axi_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

