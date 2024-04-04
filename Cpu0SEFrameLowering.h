//===-- Cpu0SEFrameLowering.h - Cpu032/64 frame lowering --------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_CPU0_CPU0SEFRAMELOWERING_H
#define LLVM_LIB_TARGET_CPU0_CPU0SEFRAMELOWERING_H

#include "Cpu0Config.h"

#include "Cpu0FrameLowering.h"

namespace llvm {

class Cpu0SEFrameLowering : public Cpu0FrameLowering {
public:
  explicit Cpu0SEFrameLowering(const Cpu0Subtarget &STI);

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  /*
   * brief: 在函数中插入序言代码 (猜测可能是补充上下文, 比如插入全局变量的地址)
   */
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;

  /*
   * brief: 在函数中插入尾声代码 (猜测可能是清理堆栈的功能,
   * 比如调用对象的析构函数)
   */
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;

  bool spillCalleeSavedRegisters(MachineBasicBlock &MBB,
                                 MachineBasicBlock::iterator MI,
                                 ArrayRef<CalleeSavedInfo> CSI,
                                 const TargetRegisterInfo *TRI) const override;

  bool hasReservedCallFrame(const MachineFunction &MF) const override;

  void determineCalleeSaves(MachineFunction &MF, BitVector &SavedRegs,
                            RegScavenger *RS) const override;
};

} // namespace llvm

#endif
