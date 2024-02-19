
//===----------------------------------------------------------------------===//
// Register Classes
//===----------------------------------------------------------------------===//

/*  RegisterTuples定义
    // RegisterTuples - Automatically generate super-registers by forming tuples of
    // sub-registers. This is useful for modeling register sequence constraints
    // with pseudo-registers that are larger than the architectural registers.
    //
    // The sub-register lists are zipped together:
    //
    //   def EvenOdd : RegisterTuples<[sube, subo], [(add R0, R2), (add R1, R3)]>;
    //
    // Generates the same registers as:
    //
    //   let SubRegIndices = [sube, subo] in {
    //     def R0_R1 : RegisterWithSubRegs<"", [R0, R1]>;
    //     def R2_R3 : RegisterWithSubRegs<"", [R2, R3]>;
    //   }
    //
    // The generated pseudo-registers inherit super-classes and fields from their
    // first sub-register. Most fields from the Register class are inferred, and
    // the AsmName and Dwarf numbers are cleared.
    //
    // RegisterTuples instances can be used in other set operations to form
    // register classes and so on. This is the only way of using the generated
    // registers.
    //
    // RegNames may be specified to supply asm names for the generated tuples.
    // If used must have the same size as the list of produced registers.
    class RegisterTuples<list<SubRegIndex> Indices, list<dag> Regs,
                         list<string> RegNames = []> {
      // SubRegs - N lists of registers to be zipped up. Super-registers are
      // synthesized from the first element of each SubRegs list, the second
      // element and so on.
      list<dag> SubRegs = Regs;

      // SubRegIndices - N SubRegIndex instances. This provides the names of the
      // sub-registers in the synthesized super-registers.
      list<SubRegIndex> SubRegIndices = Indices;

      // List of asm names for the generated tuple registers.
      list<string> RegAsmNames = RegNames;
    }
 */
def GPROut : RegisterClass<"Cpu0", [i32], 32, (add CPURegs)>;

