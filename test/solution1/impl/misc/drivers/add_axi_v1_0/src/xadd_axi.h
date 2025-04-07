// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XADD_AXI_H
#define XADD_AXI_H

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
#include "xadd_axi_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Ctrl_BaseAddress;
} XAdd_axi_Config;
#endif

typedef struct {
    u32 Ctrl_BaseAddress;
    u32 IsReady;
} XAdd_axi;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XAdd_axi_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XAdd_axi_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XAdd_axi_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XAdd_axi_ReadReg(BaseAddress, RegOffset) \
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
int XAdd_axi_Initialize(XAdd_axi *InstancePtr, u16 DeviceId);
XAdd_axi_Config* XAdd_axi_LookupConfig(u16 DeviceId);
int XAdd_axi_CfgInitialize(XAdd_axi *InstancePtr, XAdd_axi_Config *ConfigPtr);
#else
int XAdd_axi_Initialize(XAdd_axi *InstancePtr, const char* InstanceName);
int XAdd_axi_Release(XAdd_axi *InstancePtr);
#endif

void XAdd_axi_Start(XAdd_axi *InstancePtr);
u32 XAdd_axi_IsDone(XAdd_axi *InstancePtr);
u32 XAdd_axi_IsIdle(XAdd_axi *InstancePtr);
u32 XAdd_axi_IsReady(XAdd_axi *InstancePtr);
void XAdd_axi_EnableAutoRestart(XAdd_axi *InstancePtr);
void XAdd_axi_DisableAutoRestart(XAdd_axi *InstancePtr);

void XAdd_axi_Set_a(XAdd_axi *InstancePtr, u32 Data);
u32 XAdd_axi_Get_a(XAdd_axi *InstancePtr);
void XAdd_axi_Set_b(XAdd_axi *InstancePtr, u32 Data);
u32 XAdd_axi_Get_b(XAdd_axi *InstancePtr);
u32 XAdd_axi_Get_result(XAdd_axi *InstancePtr);
u32 XAdd_axi_Get_result_vld(XAdd_axi *InstancePtr);

void XAdd_axi_InterruptGlobalEnable(XAdd_axi *InstancePtr);
void XAdd_axi_InterruptGlobalDisable(XAdd_axi *InstancePtr);
void XAdd_axi_InterruptEnable(XAdd_axi *InstancePtr, u32 Mask);
void XAdd_axi_InterruptDisable(XAdd_axi *InstancePtr, u32 Mask);
void XAdd_axi_InterruptClear(XAdd_axi *InstancePtr, u32 Mask);
u32 XAdd_axi_InterruptGetEnabled(XAdd_axi *InstancePtr);
u32 XAdd_axi_InterruptGetStatus(XAdd_axi *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
