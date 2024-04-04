//===-- Cpu0.h - Top-level interface for Cpu0 representation ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM Cpu0 back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_CPU0_CPU0_H
#define LLVM_LIB_TARGET_CPU0_CPU0_H

#include "Cpu0Config.h"
#include "MCTargetDesc/Cpu0MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class Cpu0TargetMachine;
class FunctionPass;

#ifdef ENABLE_GPRESTORE
FunctionPass *createCpu0EmitGPRestorePass(Cpu0TargetMachine &TM);
#endif
FunctionPass *createCpu0DelaySlotFillerPass(Cpu0TargetMachine &TM);
FunctionPass *createCpu0DelJmpPass(Cpu0TargetMachine &TM);
FunctionPass *createCpu0LongBranchPass(Cpu0TargetMachine &TM);

} // namespace llvm

#endif
