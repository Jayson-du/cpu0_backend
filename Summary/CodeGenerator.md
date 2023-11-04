# [llvm后端CodeGenerator学习总结](https://llvm.org/docs/CodeGenerator.html)

## Cpu0后端总架构图
![Cpu0后端总架构图](./out/plantuml/Cpu0_arch/Cpu0_arch.svg)


## Cpu0后端使用LLVM提供类总结

| 类                           | 描述                                                    |
|------------------------------|---------------------------------------------------------|
| MachineInstr                 | Machine从最初以SSA形式选择产生，并一直以SSA形式出现，直到发生寄存器分配 |
| MachineBasicBlock            | 存储一系列MachineInstr指令                               |
| MachineFunction              | 存储一系列MachineBasicBlock                             |
|------------------------------|---------------------------------------------------------|
| MCStream                     |                                                         |
| MCContext                    |




| 函数                          | 描述                                                    |
|------------------------------|---------------------------------------------------------|
| BuildMI                      | * 位置: include/llvm/CodeGen/MachineInstrBuilder.h<br>* 功能: 创建任意的机器指令 |
