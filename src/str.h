//===-- core/str.h - string manipulation functions ----------------*- C -*-===//
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
/// This file contains the declaration of the String manipulation functions,
/// which provides a miscellaneous string manipulation.
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

// External headers

// System headers


//==============================================================================
//= Constants(also Enumerations)
//==============================================================================


//==============================================================================
//= Types
//==============================================================================


//==============================================================================
//= Variables
//==============================================================================


//==============================================================================
//= Functions
//==============================================================================
void STR_StripL(char *str);
void STR_StripR(char *str);
void STR_StripSharpComment(char *str);

#ifdef __cplusplus
}
#endif
