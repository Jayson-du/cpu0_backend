//===-- Cpu0SEInstrInfo.h - Cpu032/64 Instruction Information ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Cpu032/64 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_CPU0_CPU0SEINSTRINFO_H
#define LLVM_LIB_TARGET_CPU0_CPU0SEINSTRINFO_H

#include "Cpu0Config.h"

#include "Cpu0InstrInfo.h"
#include "Cpu0MachineFunction.h"
#include "Cpu0SERegisterInfo.h"

namespace llvm {

class Cpu0SEInstrInfo : public Cpu0InstrInfo {
  const Cpu0SERegisterInfo RI;

public:
  explicit Cpu0SEInstrInfo(const Cpu0Subtarget &STI);

  const Cpu0RegisterInfo &getRegisterInfo() const override;

  /**
   * @brief 重写自TargetInstrInfo::copyPhysReg,
   *        在指令选择期间,发射一条对一对物理寄存器拷贝的指令
   *
   * @param MBB
   * @param MI
   * @param DL
   * @param DestReg
   * @param SrcReg
   * @param KillSrc
   */
  void copyPhysReg(MachineBasicBlock &MBB, MachineBasicBlock::iterator MI,
                   const DebugLoc &DL, MCRegister DestReg, MCRegister SrcReg,
                   bool KillSrc) const override;

  void storeRegToStack(MachineBasicBlock &MBB, MachineBasicBlock::iterator MI,
                       Register SrcReg, bool isKill, int FrameIndex,
                       const TargetRegisterClass *RC,
                       const TargetRegisterInfo *TRI,
                       int64_t Offset) const override;

  void loadRegFromStack(MachineBasicBlock &MBB, MachineBasicBlock::iterator MI,
                        Register DestReg, int FrameIndex,
                        const TargetRegisterClass *RC,
                        const TargetRegisterInfo *TRI,
                        int64_t Offset) const override;

  //@expandPostRAPseudo
  /**
   * @brief 重写TargetInstrInfo::expandPostRAPseudo,伪指令对寄存器分配有帮助,
   *        在寄存器分配之后,仍然会存在一些伪指令,这个函数的作用就是将伪指令转为真实指令
   *
   * @param MI
   * @return true
   * @return false
   */
  bool expandPostRAPseudo(MachineInstr &MI) const override;

  /// Adjust SP by Amount bytes.
  void adjustStackPtr(unsigned SP, int64_t Amount, MachineBasicBlock &MBB,
                      MachineBasicBlock::iterator I) const override;

  /// Emit a series of instructions to load an immediate. If NewImm is a
  /// non-NULL parameter, the last instruction is not emitted, but instead
  /// its immediate operand is returned in NewImm.
  unsigned loadImmediate(int64_t Imm, MachineBasicBlock &MBB,
                         MachineBasicBlock::iterator II, const DebugLoc &DL,
                         unsigned *NewImm) const;

private:
  void expandRetLR(MachineBasicBlock &MBB, MachineBasicBlock::iterator I) const;

  unsigned getOppositeBranchOpc(unsigned Opc) const override;

  void expandEhReturn(MachineBasicBlock &MBB,
                      MachineBasicBlock::iterator I) const;
};

} // namespace llvm

#endif
