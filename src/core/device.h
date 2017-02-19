//===-- core/device.h - Leigun Device Management Facilities -------*- C -*-===//
//
//              The Leigun Embedded System Simulator Platform
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//===----------------------------------------------------------------------===//
///
/// @file
/// This file contains the declaration of device management facilities.
///
//===----------------------------------------------------------------------===//
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
//= Dependencies
//==============================================================================
// Local/Private Headers
#include "core/list.h"
#include "initializer.h"

// External headers

// System headers
#include <stdint.h>


//==============================================================================
//= Constants(also Enumerations)
//==============================================================================
typedef enum Device_DrvKind_e {
    DK_BOARD,         /// Board composed of multiple processors, devices.
    DK_MPU,           /// Processor drived by program.
    //    DK_OTHER,               /// Other peripherals.
} Device_DrvKind_t;


//==============================================================================
//= Types
//==============================================================================
/// Device_Board_t is board instance data.
typedef struct Device_Board_s { void *self; } Device_Board_t;

/// Device_MPU_t is MPU instance data.
typedef struct Device_MPU_s { void *self; } Device_MPU_t;

typedef struct Device_DrvBase_s {
    List_Element_t liste;
    Device_DrvKind_t kind;
    const char *name;
    const char *description;
} Device_DrvBase_t;

typedef struct Device_DrvBoard_s {
    Device_DrvBase_t base;
    const char *defaultconfig;
    Device_Board_t *(*create)(void);
} Device_DrvBoard_t;

typedef struct Device_DrvMPU_s {
    Device_DrvBase_t base;
    const char *defaultconfig;
    Device_MPU_t *(*create)(void);
} Device_DrvMPU_t;


//==============================================================================
//= Variables
//==============================================================================


//==============================================================================
//= Macros
//==============================================================================
#define DEVICE_REGISTER_BOARD(name_, description_, create_, defaultconfig_)    \
    static Device_DrvBoard_t Device_boardDrv_##name_ = {                       \
        .base.kind = DK_BOARD,                                                 \
        .base.name = (name_),                                                  \
        .base.description = (description_),                                    \
        .defaultconfig = (defaultconfig_),                                     \
        .create = (create_)};                                                  \
    INITIALIZER(Device_boardDrvRegister_##name_) {                             \
        Device_Register(&Device_boardDrv_##name_.base);                        \
    }

#define DEVICE_REGISTER_MPU(name_, description_, create_, defaultconfig_)      \
    static Device_DrvMPU_t Device_mpuDrv_##name_ = {                           \
        .base.kind = DK_MPU,                                                   \
        .base.name = (name_),                                                  \
        .base.description = (description_),                                    \
        .defaultconfig = (defaultconfig_),                                     \
        .create = (create_)};                                                  \
    INITIALIZER(Device_mpuRegister_##name_) {                                  \
        Device_Register(&Device_mpuDrv_##name_.base);                          \
    }


//==============================================================================
//= Functions
//==============================================================================
void Device_Register(Device_DrvBase_t *drv);

Device_Board_t *Device_CreateBoard(const char *name);

Device_MPU_t *Device_CreateMPU(const char *name);


#ifdef __cplusplus
}
#endif
