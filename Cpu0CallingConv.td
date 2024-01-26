//===-- Cpu0CallingConv.td - Calling Conventions for Cpu0 --*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for Cpu0 architecture.
//===----------------------------------------------------------------------===//

/// CCIfSubtarget - Match if the current subtarget has a feature F.

//
/*
 * brief:     描述调用约定,
 * function:  1. 参数分配的顺序
 *            2. 参数和返回值存放地址(栈上或者堆上)
 *            3. 哪个寄存器将被使用
 *            4. 调用者或被调用者是否展开堆栈
 */

/*
 *  CCIf - If the predicate matches, apply A
 *  class CCIf<string predicate, CCAction A> : CCPredicateAction<A> {
 *    string Predicate = predicate;
 *  }
 */
class CCIfSubtarget<string F, CCAction A>:
  CCIf<!strconcat("State.getTarget().getSubtarget<Cpu0Subtarget>().", F), A>;

// CCAssignToReg会将参数分配给(V0, V1, A0, A1)中第一个可以使用的寄存器
/*
 *  class CallingConv<list<CCAction> actions> {
 *    list<CCAction> Actions = actions;
 *    // If true, this calling convention will be emitted as externally visible in
 *    // the llvm namespace instead of as a static function
 *
 *    bit Entry = false;
 *
 *    bit Custom = false;
  * }
 */
def RetCC_Cpu0EABI : CallingConv<[
  // i32 are returned in registers V0, V1, A0, A1
  CCIfType<[i32], CCAssignToReg<[V0, V1, A0, A1]>>
]>;

def RetCC_Cpu0 : CallingConv<[
  CCDelegateTo<RetCC_Cpu0EABI>
]>;

def CSR_O32 : CalleeSavedRegs<(add LR, FP,
                                   (sequence "S%u", 1, 0))>;

