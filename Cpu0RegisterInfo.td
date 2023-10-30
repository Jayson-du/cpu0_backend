//===-- Cpu0RegisterInfo.td - Cpu0 Register defs -----------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the CPU0 register file
//===----------------------------------------------------------------------===//

/*
  寄存器基类
  class Register<string n> {
    string Namespace = "";
    string AsmName = n;
    string Name = n;
    int SpillSize = 0;
    int SpillAlignment = 0;
    list<Register> Aliases = [];
    list<Register> SubRegs = [];
    list<int> DwarfNumbers = [];
  }

  ----------------------------------------------------------------------===//

  DwarfRegNum - This class provides a mapping of the llvm register enumeration
  to the register numbering used by gcc and gdb.  These values are used by a
  debug information writer to describe where values may be located during
  execution.
  class DwarfRegNum<list<int> Numbers> {

    DwarfNumbers - Numbers used internally by gcc/gdb to identify the register.
    These values can be determined by locating the <target>.h file in the
    directory llvmgcc/gcc/config/<target>/ and looking for REGISTER_NAMES.  The
    order of these names correspond to the enumeration used by gcc.  A value of
    -1 indicates that the gcc number is undefined and -2 that register number
    is invalid for this mode/flavour.

    list<int> DwarfNumbers = Numbers;
  }
 */

// We have banks of 16 registers each.
class Cpu0Reg<bits<16> Enc, string n> : Register<n> {
  // For tablegen(... -gen-emitter)  in CMakeLists.txt
  let HWEncoding = Enc;

  let Namespace = "Cpu0";
}

// Cpu0 CPU Registers
class Cpu0GPRReg<bits<16> Enc, string n> : Cpu0Reg<Enc, n>;

// Co-processor 0 Registers
class Cpu0C0Reg<bits<16> Enc, string n> : Cpu0Reg<Enc, n>;

//===----------------------------------------------------------------------===//
//@Registers (定义所有寄存器信息)
//===----------------------------------------------------------------------===//
// The register string, such as "9" or "gp" will show on "llvm-objdump -d"
//@ All registers definition
let Namespace = "Cpu0" in {
  //@ General Purpose Registers
  def ZERO : Cpu0GPRReg<0,  "zero">, DwarfRegNum<[0]>;
  def AT   : Cpu0GPRReg<1,  "1">,    DwarfRegNum<[1]>;
  def V0   : Cpu0GPRReg<2,  "2">,    DwarfRegNum<[2]>;
  def V1   : Cpu0GPRReg<3,  "3">,    DwarfRegNum<[3]>;
  def A0   : Cpu0GPRReg<4,  "4">,    DwarfRegNum<[4]>;
  def A1   : Cpu0GPRReg<5,  "5">,    DwarfRegNum<[5]>;
  def T9   : Cpu0GPRReg<6,  "t9">,   DwarfRegNum<[6]>;
  def T0   : Cpu0GPRReg<7,  "7">,    DwarfRegNum<[7]>;
  def T1   : Cpu0GPRReg<8,  "8">,    DwarfRegNum<[8]>;
  def S0   : Cpu0GPRReg<9,  "9">,    DwarfRegNum<[9]>;
  def S1   : Cpu0GPRReg<10, "10">,   DwarfRegNum<[10]>;
  def GP   : Cpu0GPRReg<11, "gp">,   DwarfRegNum<[11]>;
  def FP   : Cpu0GPRReg<12, "fp">,   DwarfRegNum<[12]>;
  def SP   : Cpu0GPRReg<13, "sp">,   DwarfRegNum<[13]>;
  def LR   : Cpu0GPRReg<14, "lr">,   DwarfRegNum<[14]>;
  def SW   : Cpu0GPRReg<15, "sw">,   DwarfRegNum<[15]>;
//  def MAR  : Register< 16, "mar">,  DwarfRegNum<[16]>;
//  def MDR  : Register< 17, "mdr">,  DwarfRegNum<[17]>;

  // Hi/Lo registers number and name
  def HI   : Cpu0Reg<0, "ac0">, DwarfRegNum<[18]>;
  def LO   : Cpu0Reg<0, "ac0">, DwarfRegNum<[19]>;
  def PC   : Cpu0C0Reg<0, "pc">,  DwarfRegNum<[20]>;
  def EPC  : Cpu0C0Reg<1, "epc">, DwarfRegNum<[21]>;
}

//===----------------------------------------------------------------------===//
//@Register Classes
//===----------------------------------------------------------------------===//

/*
    class RegisterClass<string namespace,                               // 定义Namespace

                        list<ValueType> regTypes,                       // 定义寄存器类型值的列表(如i16, i32,
                                                                        // f32, f64)所有寄存器的类型值必须一致;
                                                                        // (include/llvm/CodeGen/ValueTypes.td)
                        int alignment,                                  // 定义寄存器对齐方式

                        dag regList> {                                  // 指定哪个寄存器在RegisterClass中,
                                                                        // 如果没有指定可选的分配顺序方法，则
                                                                        // regList还定义寄存器分配器使用的分配顺序

      string Namespace = namespace;
      list<ValueType> RegTypes = regTypes;
      int Size = 0;  // spill size, in bits; zero lets tblgen pick the size
      int Alignment = alignment;

      // CopyCost is the cost of copying a value between two registers
      // default value 1 means a single instruction
      // A negative value means copying is extremely expensive or impossible
      int CopyCost = 1;
      dag MemberList = regList;

      // for register classes that are subregisters of this class
      list<RegisterClass> SubRegClassList = [];

      code MethodProtos = [{}];  // to insert arbitrary code
      code MethodBodies = [{}];
    }

    下面分别定义4个RegisterClass对象(CPURegs, HILO, SR, C0Regs), 4个RegisterClass对象分别添加上面对应的寄存器信息
 */

def CPURegs : RegisterClass<"Cpu0", [i32], 32, (add
  // Reserved
  ZERO, AT,
  // Return Values and Arguments
  V0, V1, A0, A1,
  // Not preserved across procedure calls
  T9, T0, T1,
  // Callee save
  S0, S1,
  // Reserved
  GP, FP,
  SP, LR, SW)>;

// Hi/Lo Registers class
def HILO   : RegisterClass<"Cpu0", [i32], 32, (add HI, LO)>;

//@Status Registers class
def SR     : RegisterClass<"Cpu0", [i32], 32, (add SW)>;

//@Co-processor 0 Registers class
def C0Regs : RegisterClass<"Cpu0", [i32], 32, (add PC, EPC)>;

