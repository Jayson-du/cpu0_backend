# 产生名为LLVMCpu0CodeGen的静态库


cmake_minimum_required(VERSION 3.22)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 导入LLVM的配置文件
set(LLVM_INSTALL_PREFIX "/usr/lib/llvm-14")

list(APPEND CMAKE_PREFIX_PATH ${LLVM_INSTALL_PREFIX}/lib/cmake/llvm/)

find_package(LLVM REQUIRED CONFIG)

# include(${CMAKE_PREFIX_PATH}/)

file(GLOB CMAKE_FILES ${CMAKE_PREFIX_PATH}//*.cmake)

# 遍历每个 .cmake 文件并引用
foreach(CMAKE_FILE IN LISTS CMAKE_FILES)
    include(${CMAKE_FILE})
endforeach()

# 包含LLVM相关模块
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_llvm_component_group(Cpu0)


set(LLVM_TARGET_DEFINITIONS Cpu0Asm.td)
tablegen(LLVM Cpu0GenAsmMatcher.inc -gen-asm-matcher)

set(LLVM_TARGET_DEFINITIONS Cpu0Other.td)

# Generate Cpu0GenRegisterInfo.inc and Cpu0GenInstrInfo.inc which included by 
#  your hand code C++ files. 
# Cpu0GenRegisterInfo.inc came from Cpu0RegisterInfo.td, Cpu0GenInstrInfo.inc 
#  came from Cpu0InstrInfo.td.
tablegen(LLVM Cpu0GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM Cpu0GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM Cpu0GenDisassemblerTables.inc -gen-disassembler)
tablegen(LLVM Cpu0GenCodeEmitter.inc -gen-emitter)
tablegen(LLVM Cpu0GenMCCodeEmitter.inc -gen-emitter)

tablegen(LLVM Cpu0GenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM Cpu0GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM Cpu0GenCallingConv.inc -gen-callingconv)
tablegen(LLVM Cpu0GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM Cpu0GenMCPseudoLowering.inc -gen-pseudo-lowering)

# Cpu0CommonTableGen must be defined
add_public_tablegen_target(Cpu0CommonTableGen)

# Cpu0CodeGen should match with LLVMBuild.txt Cpu0CodeGen
add_llvm_target(Cpu0CodeGen
  Cpu0AnalyzeImmediate.cpp
  Cpu0AsmPrinter.cpp
  Cpu0MCInstLower.cpp
  Cpu0DelaySlotFiller.cpp
  Cpu0DelUselessJMP.cpp
  Cpu0EmitGPRestore.cpp
  Cpu0FrameLowering.cpp
  Cpu0LongBranch.cpp
  Cpu0InstrInfo.cpp
  Cpu0ISelLowering.cpp
  Cpu0MachineFunction.cpp
  Cpu0RegisterInfo.cpp
  Cpu0SEFrameLowering.cpp
  Cpu0SEInstrInfo.cpp
  Cpu0SEISelLowering.cpp
  Cpu0SERegisterInfo.cpp
  Cpu0Subtarget.cpp
  Cpu0TargetObjectFile.cpp
  Cpu0ISelDAGToDAG.cpp
  Cpu0SEISelDAGToDAG.cpp
  Cpu0TargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  Core
  MC
  Cpu0Desc
  Cpu0Info
  Cpu0AsmParser
  Cpu0AsmPrinter
  Cpu0Disassembler
  SelectionDAG
  Support
  Target
  GlobalISel

  ADD_TO_COMPONENT
  Cpu0
  )

# Should match with "subdirectories =  MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(InstPrinter)
add_subdirectory(Disassembler)
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
add_subdirectory(AsmParser)

