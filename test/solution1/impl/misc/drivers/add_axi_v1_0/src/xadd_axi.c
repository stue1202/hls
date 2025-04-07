// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xadd_axi.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XAdd_axi_CfgInitialize(XAdd_axi *InstancePtr, XAdd_axi_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XAdd_axi_Start(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_AP_CTRL) & 0x80;
    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XAdd_axi_IsDone(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XAdd_axi_IsIdle(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XAdd_axi_IsReady(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XAdd_axi_EnableAutoRestart(XAdd_axi *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_AP_CTRL, 0x80);
}

void XAdd_axi_DisableAutoRestart(XAdd_axi *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_AP_CTRL, 0);
}

void XAdd_axi_Set_a(XAdd_axi *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_A_DATA, Data);
}

u32 XAdd_axi_Get_a(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_A_DATA);
    return Data;
}

void XAdd_axi_Set_b(XAdd_axi *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_B_DATA, Data);
}

u32 XAdd_axi_Get_b(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_B_DATA);
    return Data;
}

u32 XAdd_axi_Get_result(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_RESULT_DATA);
    return Data;
}

u32 XAdd_axi_Get_result_vld(XAdd_axi *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_RESULT_CTRL);
    return Data & 0x1;
}

void XAdd_axi_InterruptGlobalEnable(XAdd_axi *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_GIE, 1);
}

void XAdd_axi_InterruptGlobalDisable(XAdd_axi *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_GIE, 0);
}

void XAdd_axi_InterruptEnable(XAdd_axi *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_IER);
    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_IER, Register | Mask);
}

void XAdd_axi_InterruptDisable(XAdd_axi *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_IER);
    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_IER, Register & (~Mask));
}

void XAdd_axi_InterruptClear(XAdd_axi *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdd_axi_WriteReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_ISR, Mask);
}

u32 XAdd_axi_InterruptGetEnabled(XAdd_axi *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_IER);
}

u32 XAdd_axi_InterruptGetStatus(XAdd_axi *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAdd_axi_ReadReg(InstancePtr->Ctrl_BaseAddress, XADD_AXI_CTRL_ADDR_ISR);
}

