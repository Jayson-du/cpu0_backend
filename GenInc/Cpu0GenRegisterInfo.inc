/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register Enum Values                                                *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM

namespace llvm {

// MCRegisterClass是系统生成, MCRegisterClass是目标寄存器的基类
class MCRegisterClass;

// Cpu0MCRegisterClasses, 是根据目标"Cpu0"拼接"MCRegisterClasses",
// 在文件最前面声明一个Cpu0MCRegisterClasses数组; (系统默认)
extern const MCRegisterClass Cpu0MCRegisterClasses[];

namespace Cpu0 {
// 这里 "1 ~ 20" 是根据插入到CodeGenRegister先后顺序产生的(函数位置: CodeGenRegBank::getReg)
enum {
  NoRegister,   // 这个是TableGen自己产生的
  AT = 1,
  EPC = 2,
  FP = 3,
  GP = 4,
  HI = 5,
  LO = 6,
  LR = 7,
  PC = 8,
  SP = 9,
  SW = 10,
  ZERO = 11,
  A0 = 12,
  A1 = 13,
  S0 = 14,
  S1 = 15,
  T0 = 16,
  T1 = 17,
  T9 = 18,
  V0 = 19,
  V1 = 20,
  NUM_TARGET_REGS // 21 // TableGen自己产生的
};
} // end namespace Cpu0

// Register classes
// 定义通过TableGen文件(Cpu0RegisterInfo.td: 130 ~ 150)定义寄存器分类情况,
// 其中"CPU0Regs", "GPRout", "C0", "SR"是通过TableGen文件定义的, "RegClassID"是TableGen补充的
namespace Cpu0 {
enum {
  CPURegsRegClassID = 0,
  GPROutRegClassID = 1,
  C0RegsRegClassID = 2,
  HILORegClassID = 3,
  SRRegClassID = 4,

};
} // end namespace Cpu0

// Register pressure sets enum.
namespace Cpu0 {
enum RegisterPressureSets {
  SR = 0,
  C0Regs = 1,
  HILO = 2,
  GPROut = 3,
};
} // end namespace Cpu0

} // end namespace llvm

#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* MC Register Information                                                    *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC

namespace llvm {

extern const MCPhysReg Cpu0RegDiffLists[] = {
  /* 0 */ 65535, 0,
};

extern const LaneBitmask Cpu0LaneMaskLists[] = {
  /* 0 */ LaneBitmask(0x0000000000000000), LaneBitmask::getAll(),
};

extern const uint16_t Cpu0SubRegIdxLists[] = {
  /* 0 */ 0,
};

// 65535是TableGen自己生成的与td文件无关
extern const MCRegisterInfo::SubRegCoveredBits Cpu0SubRegIdxRanges[] = {
  { 65535, 65535 },
};

extern const char Cpu0RegStrings[] = {
  /* 0 */ 'A', '0', 0,
  /* 3 */ 'S', '0', 0,
  /* 6 */ 'T', '0', 0,
  /* 9 */ 'V', '0', 0,
  /* 12 */ 'A', '1', 0,
  /* 15 */ 'S', '1', 0,
  /* 18 */ 'T', '1', 0,
  /* 21 */ 'V', '1', 0,
  /* 24 */ 'T', '9', 0,
  /* 27 */ 'E', 'P', 'C', 0,
  /* 31 */ 'H', 'I', 0,
  /* 34 */ 'L', 'O', 0,
  /* 37 */ 'Z', 'E', 'R', 'O', 0,
  /* 42 */ 'F', 'P', 0,
  /* 45 */ 'G', 'P', 0,
  /* 48 */ 'S', 'P', 0,
  /* 51 */ 'L', 'R', 0,
  /* 54 */ 'A', 'T', 0,
  /* 57 */ 'S', 'W', 0,

};

/// MCRegisterDesc - This record contains information about a particular
/// register. The SubRegs field is a zero teriminated array oear registers that
/// are sub-registers of the specific register, e.g. AL, AH are sub-registers
/// of AX. The SuperRegs field is a zero terminated array of registers that are
/// super-registers of the specific register, e.g. RAX, EAX, are
/// super-registers of AX.
/// struct MCRegisterDesc {
///   uint32_t  Name;             printable name for the reg (for debugging)
///   uint32_t  SubRegs;          Sub-register set, described above
///   uint32_t  SuperRegs;        Super-register set, described above
///   uint32_t  SubRegIndices;    Offset into MCRI::SubRegIndices of a list of sub-register
///                               indices for each sub-register in SubRegs
///   uint32_t  RegUnits;         Point to the list of register units. The low 4 bits holds
///                               the Scale, the high bits hold an offset into DiffLists.
///                               See MCRegUnitIterator.
///   uint32_t  RegUnitLaneMasks; Index into list with lane mask sequences. The sequence
///                               contains a lanemask for every register unit.
/// }
extern const MCRegisterDesc Cpu0RegDesc[] = { // Descriptors
  { 2, 0, 0, 0, 0, 0 },
  { 54, 1, 1, 0, 1, 0 },
  { 27, 1, 1, 0, 1, 0 },
  { 42, 1, 1, 0, 1, 0 },
  { 45, 1, 1, 0, 1, 0 },
  { 31, 1, 1, 0, 1, 0 },
  { 34, 1, 1, 0, 1, 0 },
  { 51, 1, 1, 0, 1, 0 },
  { 28, 1, 1, 0, 1, 0 },
  { 48, 1, 1, 0, 1, 0 },
  { 57, 1, 1, 0, 1, 0 },
  { 37, 1, 1, 0, 1, 0 },
  { 0, 1, 1, 0, 1, 0 },
  { 12, 1, 1, 0, 1, 0 },
  { 3, 1, 1, 0, 1, 0 },
  { 15, 1, 1, 0, 1, 0 },
  { 6, 1, 1, 0, 1, 0 },
  { 18, 1, 1, 0, 1, 0 },
  { 24, 1, 1, 0, 1, 0 },
  { 9, 1, 1, 0, 1, 0 },
  { 21, 1, 1, 0, 1, 0 },
};

extern const MCPhysReg Cpu0RegUnitRoots[][2] = {
  { Cpu0::AT },
  { Cpu0::EPC },
  { Cpu0::FP },
  { Cpu0::GP },
  { Cpu0::HI },
  { Cpu0::LO },
  { Cpu0::LR },
  { Cpu0::PC },
  { Cpu0::SP },
  { Cpu0::SW },
  { Cpu0::ZERO },
  { Cpu0::A0 },
  { Cpu0::A1 },
  { Cpu0::S0 },
  { Cpu0::S1 },
  { Cpu0::T0 },
  { Cpu0::T1 },
  { Cpu0::T9 },
  { Cpu0::V0 },
  { Cpu0::V1 },
};

namespace {     // Register classes...
  // CPURegs Register Class...
  const MCPhysReg CPURegs[] = {
    Cpu0::ZERO, Cpu0::AT, Cpu0::V0, Cpu0::V1, Cpu0::A0, Cpu0::A1, Cpu0::T9, Cpu0::T0, Cpu0::T1, Cpu0::S0, Cpu0::S1, Cpu0::GP, Cpu0::FP, Cpu0::SP, Cpu0::LR, Cpu0::SW,
  };

  // CPURegs Bit set.
  const uint8_t CPURegsBits[] = {
    0x9a, 0xfe, 0x1f,
  };

  // GPROut Register Class...
  const MCPhysReg GPROut[] = {
    Cpu0::ZERO, Cpu0::AT, Cpu0::V0, Cpu0::V1, Cpu0::A0, Cpu0::A1, Cpu0::T9, Cpu0::T0, Cpu0::T1, Cpu0::S0, Cpu0::S1, Cpu0::GP, Cpu0::FP, Cpu0::SP, Cpu0::LR,
  };

  // GPROut Bit set.
  const uint8_t GPROutBits[] = {
    0x9a, 0xfa, 0x1f,
  };

  // C0Regs Register Class...
  const MCPhysReg C0Regs[] = {
    Cpu0::PC, Cpu0::EPC,
  };

  // C0Regs Bit set.
  const uint8_t C0RegsBits[] = {
    0x04, 0x01,
  };

  // HILO Register Class...
  const MCPhysReg HILO[] = {
    Cpu0::HI, Cpu0::LO,
  };

  // HILO Bit set.
  const uint8_t HILOBits[] = {
    0x60,
  };

  // SR Register Class...
  const MCPhysReg SR[] = {
    Cpu0::SW,
  };

  // SR Bit set.
  const uint8_t SRBits[] = {
    0x00, 0x04,
  };

} // end anonymous namespace

extern const char Cpu0RegClassStrings[] = {
  /* 0 */ 'H', 'I', 'L', 'O', 0,
  /* 5 */ 'S', 'R', 0,
  /* 8 */ 'C', '0', 'R', 'e', 'g', 's', 0,
  /* 15 */ 'C', 'P', 'U', 'R', 'e', 'g', 's', 0,
  /* 23 */ 'G', 'P', 'R', 'O', 'u', 't', 0,

};

extern const MCRegisterClass Cpu0MCRegisterClasses[] = {
  { CPURegs, CPURegsBits, 15, 16, sizeof(CPURegsBits), Cpu0::CPURegsRegClassID, 1, true },
  { GPROut, GPROutBits, 23, 15, sizeof(GPROutBits), Cpu0::GPROutRegClassID, 1, true },
  { C0Regs, C0RegsBits, 8, 2, sizeof(C0RegsBits), Cpu0::C0RegsRegClassID, 1, true },
  { HILO, HILOBits, 0, 2, sizeof(HILOBits), Cpu0::HILORegClassID, 1, true },
  { SR, SRBits, 5, 1, sizeof(SRBits), Cpu0::SRRegClassID, 1, true },
};

// Cpu0 Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0DwarfFlavour0Dwarf2L[] = {
  { 0U, Cpu0::ZERO },
  { 1U, Cpu0::AT },
  { 2U, Cpu0::V0 },
  { 3U, Cpu0::V1 },
  { 4U, Cpu0::A0 },
  { 5U, Cpu0::A1 },
  { 6U, Cpu0::T9 },
  { 7U, Cpu0::T0 },
  { 8U, Cpu0::T1 },
  { 9U, Cpu0::S0 },
  { 10U, Cpu0::S1 },
  { 11U, Cpu0::GP },
  { 12U, Cpu0::FP },
  { 13U, Cpu0::SP },
  { 14U, Cpu0::LR },
  { 15U, Cpu0::SW },
  { 18U, Cpu0::HI },
  { 19U, Cpu0::LO },
  { 20U, Cpu0::PC },
  { 21U, Cpu0::EPC },
};
extern const unsigned Cpu0DwarfFlavour0Dwarf2LSize = array_lengthof(Cpu0DwarfFlavour0Dwarf2L);

extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0EHFlavour0Dwarf2L[] = {
  { 0U, Cpu0::ZERO },
  { 1U, Cpu0::AT },
  { 2U, Cpu0::V0 },
  { 3U, Cpu0::V1 },
  { 4U, Cpu0::A0 },
  { 5U, Cpu0::A1 },
  { 6U, Cpu0::T9 },
  { 7U, Cpu0::T0 },
  { 8U, Cpu0::T1 },
  { 9U, Cpu0::S0 },
  { 10U, Cpu0::S1 },
  { 11U, Cpu0::GP },
  { 12U, Cpu0::FP },
  { 13U, Cpu0::SP },
  { 14U, Cpu0::LR },
  { 15U, Cpu0::SW },
  { 18U, Cpu0::HI },
  { 19U, Cpu0::LO },
  { 20U, Cpu0::PC },
  { 21U, Cpu0::EPC },
};
extern const unsigned Cpu0EHFlavour0Dwarf2LSize = array_lengthof(Cpu0EHFlavour0Dwarf2L);

extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0DwarfFlavour0L2Dwarf[] = {
  { Cpu0::AT, 1U },
  { Cpu0::EPC, 21U },
  { Cpu0::FP, 12U },
  { Cpu0::GP, 11U },
  { Cpu0::HI, 18U },
  { Cpu0::LO, 19U },
  { Cpu0::LR, 14U },
  { Cpu0::PC, 20U },
  { Cpu0::SP, 13U },
  { Cpu0::SW, 15U },
  { Cpu0::ZERO, 0U },
  { Cpu0::A0, 4U },
  { Cpu0::A1, 5U },
  { Cpu0::S0, 9U },
  { Cpu0::S1, 10U },
  { Cpu0::T0, 7U },
  { Cpu0::T1, 8U },
  { Cpu0::T9, 6U },
  { Cpu0::V0, 2U },
  { Cpu0::V1, 3U },
};
extern const unsigned Cpu0DwarfFlavour0L2DwarfSize = array_lengthof(Cpu0DwarfFlavour0L2Dwarf);

extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0EHFlavour0L2Dwarf[] = {
  { Cpu0::AT, 1U },
  { Cpu0::EPC, 21U },
  { Cpu0::FP, 12U },
  { Cpu0::GP, 11U },
  { Cpu0::HI, 18U },
  { Cpu0::LO, 19U },
  { Cpu0::LR, 14U },
  { Cpu0::PC, 20U },
  { Cpu0::SP, 13U },
  { Cpu0::SW, 15U },
  { Cpu0::ZERO, 0U },
  { Cpu0::A0, 4U },
  { Cpu0::A1, 5U },
  { Cpu0::S0, 9U },
  { Cpu0::S1, 10U },
  { Cpu0::T0, 7U },
  { Cpu0::T1, 8U },
  { Cpu0::T9, 6U },
  { Cpu0::V0, 2U },
  { Cpu0::V1, 3U },
};
extern const unsigned Cpu0EHFlavour0L2DwarfSize = array_lengthof(Cpu0EHFlavour0L2Dwarf);

extern const uint16_t Cpu0RegEncodingTable[] = {
  0,
  1,
  1,
  12,
  11,
  0,
  0,
  14,
  0,
  13,
  15,
  0,
  4,
  5,
  9,
  10,
  7,
  8,
  6,
  2,
  3,
};
static inline void InitCpu0MCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(Cpu0RegDesc, 21, RA, PC, Cpu0MCRegisterClasses, 5, Cpu0RegUnitRoots, 20, Cpu0RegDiffLists, Cpu0LaneMaskLists, Cpu0RegStrings, Cpu0RegClassStrings, Cpu0SubRegIdxLists, 1,
Cpu0SubRegIdxRanges, Cpu0RegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(Cpu0DwarfFlavour0Dwarf2L, Cpu0DwarfFlavour0Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(Cpu0EHFlavour0Dwarf2L, Cpu0EHFlavour0Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(Cpu0DwarfFlavour0L2Dwarf, Cpu0DwarfFlavour0L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(Cpu0EHFlavour0L2Dwarf, Cpu0EHFlavour0L2DwarfSize, true);
    break;
  }
}

} // end namespace llvm

#endif // GET_REGINFO_MC_DESC

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Register Information Header Fragment                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_HEADER
#undef GET_REGINFO_HEADER

#include "llvm/CodeGen/TargetRegisterInfo.h"

namespace llvm {

class Cpu0FrameLowering;

struct Cpu0GenRegisterInfo : public TargetRegisterInfo
{
  explicit Cpu0GenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0,
                               unsigned PC = 0, unsigned HwMode = 0);

  const RegClassWeight &getRegClassWeight(const TargetRegisterClass *RC) const override;

  // 获取寄存器的权重
  unsigned getRegUnitWeight(unsigned RegUnit) const override;

  // 在LLVM中， "register pressure"(寄存器压力)是指在编译器优化过程中, 由于寄存器数量有限,
  // 需要将变量存储到寄存器中的需求超过了可用寄存器数量, 从而导致需要频繁地将变两冲寄存器中保存
  // 到内存中或者从内存中加载到寄存器中; 这种频繁的数据传输会降低程序性能
  unsigned getNumRegPressureSets() const override;

  const char *getRegPressureSetName(unsigned Idx) const override;

  unsigned getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const override;

  const int *getRegClassPressureSets(const TargetRegisterClass *RC) const override;

  const int *getRegUnitPressureSets(unsigned RegUnit) const override;

  ArrayRef<const char *> getRegMaskNames() const override;

  ArrayRef<const uint32_t *> getRegMasks() const override;

  /// Devirtualized TargetFrameLowering.
  static const Cpu0FrameLowering *getFrameLowering(const MachineFunction &MF);
};

namespace Cpu0 { // Register classes
  extern const TargetRegisterClass CPURegsRegClass;
  extern const TargetRegisterClass GPROutRegClass;
  extern const TargetRegisterClass C0RegsRegClass;
  extern const TargetRegisterClass HILORegClass;
  extern const TargetRegisterClass SRRegClass;
} // end namespace Cpu0

} // end namespace llvm

#endif // GET_REGINFO_HEADER

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register and Register Classes Information                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_TARGET_DESC
#undef GET_REGINFO_TARGET_DESC

namespace llvm {

extern const MCRegisterClass Cpu0MCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i32, MVT::Other,
};

static const char *const SubRegIndexNameTable[] = { "" };


static const LaneBitmask SubRegIndexLaneMaskTable[] = {
  LaneBitmask::getAll(),
 };



static const TargetRegisterInfo::RegClassInfo RegClassInfos[] = {
  // Mode = 0 (Default)
  { 32, 32, 32, VTLists+0 },    // CPURegs
  { 32, 32, 32, VTLists+0 },    // GPROut
  { 32, 32, 32, VTLists+0 },    // C0Regs
  { 32, 32, 32, VTLists+0 },    // HILO
  { 32, 32, 32, VTLists+0 },    // SR
};

static const TargetRegisterClass *const NullRegClasses[] = { nullptr };

static const uint32_t CPURegsSubClassMask[] = {
  0x00000013,
};

static const uint32_t GPROutSubClassMask[] = {
  0x00000002,
};

static const uint32_t C0RegsSubClassMask[] = {
  0x00000004,
};

static const uint32_t HILOSubClassMask[] = {
  0x00000008,
};

static const uint32_t SRSubClassMask[] = {
  0x00000010,
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 0,
};

static const TargetRegisterClass *const GPROutSuperclasses[] = {
  &Cpu0::CPURegsRegClass,
  nullptr
};

static const TargetRegisterClass *const SRSuperclasses[] = {
  &Cpu0::CPURegsRegClass,
  nullptr
};


namespace Cpu0 {   // Register class instances
  extern const TargetRegisterClass CPURegsRegClass = {
    &Cpu0MCRegisterClasses[CPURegsRegClassID],
    CPURegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass GPROutRegClass = {
    &Cpu0MCRegisterClasses[GPROutRegClassID],
    GPROutSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    GPROutSuperclasses,
    nullptr
  };

  extern const TargetRegisterClass C0RegsRegClass = {
    &Cpu0MCRegisterClasses[C0RegsRegClassID],
    C0RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass HILORegClass = {
    &Cpu0MCRegisterClasses[HILORegClassID],
    HILOSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass SRRegClass = {
    &Cpu0MCRegisterClasses[SRRegClassID],
    SRSubClassMask,
    SuperRegIdxSeqs + 0,
    LaneBitmask(0x0000000000000001),
    0,
    false, /* HasDisjunctSubRegs */
    false, /* CoveredBySubRegs */
    SRSuperclasses,
    nullptr
  };

} // end namespace Cpu0

namespace {
  const TargetRegisterClass *const RegisterClasses[] = {
    &Cpu0::CPURegsRegClass,
    &Cpu0::GPROutRegClass,
    &Cpu0::C0RegsRegClass,
    &Cpu0::HILORegClass,
    &Cpu0::SRRegClass,
  };
} // end anonymous namespace

static const TargetRegisterInfoDesc Cpu0RegInfoDesc[] = { // Extra Descriptors
  { 0, false },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
  { 0, true },
};
/// Get the weight in units of pressure for this register class.
const RegClassWeight &Cpu0GenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 16},  	// CPURegs
    {1, 15},  	// GPROut
    {1, 2},  	// C0Regs
    {1, 2},  	// HILO
    {1, 1},  	// SR
  };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned Cpu0GenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 20 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned Cpu0GenRegisterInfo::getNumRegPressureSets() const {
  return 4;
}

// Get the name of this register unit pressure set.
const char *Cpu0GenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *const PressureNameTable[] = {
    "SR",
    "C0Regs",
    "HILO",
    "GPROut",
  };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned Cpu0GenRegisterInfo::
getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const {
  static const uint8_t PressureLimitTable[] = {
    1,  	// 0: SR
    2,  	// 1: C0Regs
    2,  	// 2: HILO
    16,  	// 3: GPROut
  };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
  /* 0 */ 1, -1,
  /* 2 */ 2, -1,
  /* 4 */ 0, 3, -1,
};

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int *Cpu0GenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const uint8_t RCSetStartTable[] = {
    5,5,0,2,4,};
  return &RCSetsTable[RCSetStartTable[RC->getID()]];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int *Cpu0GenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 20 && "invalid register unit");
  static const uint8_t RUSetStartTable[] = {
    5,0,5,5,2,2,5,0,5,4,5,5,5,5,5,5,5,5,5,5,};
  return &RCSetsTable[RUSetStartTable[RegUnit]];
}

extern const MCRegisterDesc Cpu0RegDesc[];
extern const MCPhysReg Cpu0RegDiffLists[];
extern const LaneBitmask Cpu0LaneMaskLists[];
extern const char Cpu0RegStrings[];
extern const char Cpu0RegClassStrings[];
extern const MCPhysReg Cpu0RegUnitRoots[][2];
extern const uint16_t Cpu0SubRegIdxLists[];
extern const MCRegisterInfo::SubRegCoveredBits Cpu0SubRegIdxRanges[];
extern const uint16_t Cpu0RegEncodingTable[];
// Cpu0 Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0DwarfFlavour0Dwarf2L[];
extern const unsigned Cpu0DwarfFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0EHFlavour0Dwarf2L[];
extern const unsigned Cpu0EHFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0DwarfFlavour0L2Dwarf[];
extern const unsigned Cpu0DwarfFlavour0L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair Cpu0EHFlavour0L2Dwarf[];
extern const unsigned Cpu0EHFlavour0L2DwarfSize;

Cpu0GenRegisterInfo::
Cpu0GenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour,
      unsigned PC, unsigned HwMode)
  : TargetRegisterInfo(Cpu0RegInfoDesc, RegisterClasses, RegisterClasses+5,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable,
             LaneBitmask(0xFFFFFFFFFFFFFFFF), RegClassInfos, HwMode) {
  InitMCRegisterInfo(Cpu0RegDesc, 21, RA, PC,
                     Cpu0MCRegisterClasses, 5,
                     Cpu0RegUnitRoots,
                     20,
                     Cpu0RegDiffLists,
                     Cpu0LaneMaskLists,
                     Cpu0RegStrings,
                     Cpu0RegClassStrings,
                     Cpu0SubRegIdxLists,
                     1,
                     Cpu0SubRegIdxRanges,
                     Cpu0RegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(Cpu0DwarfFlavour0Dwarf2L, Cpu0DwarfFlavour0Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(Cpu0EHFlavour0Dwarf2L, Cpu0EHFlavour0Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(Cpu0DwarfFlavour0L2Dwarf, Cpu0DwarfFlavour0L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(Cpu0EHFlavour0L2Dwarf, Cpu0EHFlavour0L2DwarfSize, true);
    break;
  }
}

static const MCPhysReg CSR_O32_SaveList[] = { Cpu0::LR, Cpu0::FP, Cpu0::S1, Cpu0::S0, 0 };
static const uint32_t CSR_O32_RegMask[] = { 0x0000c088, };


ArrayRef<const uint32_t *> Cpu0GenRegisterInfo::getRegMasks() const {
  static const uint32_t *const Masks[] = {
    CSR_O32_RegMask,
  };
  return makeArrayRef(Masks);
}

ArrayRef<const char *> Cpu0GenRegisterInfo::getRegMaskNames() const {
  static const char *const Names[] = {
    "CSR_O32",
  };
  return makeArrayRef(Names);
}

const Cpu0FrameLowering *
Cpu0GenRegisterInfo::getFrameLowering(const MachineFunction &MF) {
  return static_cast<const Cpu0FrameLowering *>(
      MF.getSubtarget().getFrameLowering());
}

} // end namespace llvm

#endif // GET_REGINFO_TARGET_DESC

