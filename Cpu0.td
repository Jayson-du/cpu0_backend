//===-- Cpu0.td - Describe the Cpu0 Target Machine ---------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Without this will have error: 'cpu032I' is not a recognized processor for
//  this target (ignoring processor)
//===----------------------------------------------------------------------===//
// Cpu0 Subtarget features                                                    //
//===----------------------------------------------------------------------===//

/*  SubtargetFeature定义
    // SubtargetFeature - A characteristic of the chip set.
    class SubtargetFeature<string n, string a,  string v, string d,
                        list<SubtargetFeature> i = []> {
    // 定义芯片系列
    string Name = n;

    // 特征名
    string Attribute = a;

    // 特征值
    string Value = v;

    // Desc - Feature description.  Used by command line (-mattr=) to display help
    // information.
    //
    string Desc = d;

    // Implies - Features that this feature implies are present. If one of those
    // features isn't set, then this one shouldn't be set either.
    //
    list<SubtargetFeature> Implies = i;
    }
*/

def FeatureChapter3_1  : SubtargetFeature<"ch3_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter3_2  : SubtargetFeature<"ch3_2", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter3_3  : SubtargetFeature<"ch3_3", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter3_4  : SubtargetFeature<"ch3_4", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter3_5  : SubtargetFeature<"ch3_5", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter4_1  : SubtargetFeature<"ch4_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter4_2  : SubtargetFeature<"ch4_2", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter5_1  : SubtargetFeature<"ch5_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter6_1  : SubtargetFeature<"ch6_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter7_1  : SubtargetFeature<"ch7_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter8_1  : SubtargetFeature<"ch8_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter8_2  : SubtargetFeature<"ch8_2", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter9_1  : SubtargetFeature<"ch9_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter9_2  : SubtargetFeature<"ch9_2", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter9_3  : SubtargetFeature<"ch9_3", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter10_1 : SubtargetFeature<"ch10_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter11_1 : SubtargetFeature<"ch11_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter11_2 : SubtargetFeature<"ch11_2", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapter12_1 : SubtargetFeature<"ch12_1", "HasChapterDummy", "true",
                                "Enable Chapter instructions.">;
def FeatureChapterAll  : SubtargetFeature<"chall", "HasChapterDummy", "true",
                                "Enable Chapter instructions.",
                                [FeatureChapter3_1, FeatureChapter3_2,
                                 FeatureChapter3_3, FeatureChapter3_4,
                                 FeatureChapter3_5,
                                 FeatureChapter4_1, FeatureChapter4_2,
                                 FeatureChapter5_1, FeatureChapter6_1,
                                 FeatureChapter7_1, FeatureChapter8_1,
                                 FeatureChapter8_2, FeatureChapter9_1,
                                 FeatureChapter9_2, FeatureChapter9_3,
                                 FeatureChapter10_1,
                                 FeatureChapter11_1, FeatureChapter11_2,
                                 FeatureChapter12_1]>;

def FeatureCmp         : SubtargetFeature<"cmp", "HasCmp", "true",
                                "Enable 'cmp' instructions.">;
def FeatureSlt         : SubtargetFeature<"slt", "HasSlt", "true",
                                "Enable 'slt' instructions.">;
def FeatureCpu032I     : SubtargetFeature<"cpu032I", "Cpu0ArchVersion",
                                "Cpu032I", "Cpu032I ISA Support",
                                [FeatureCmp, FeatureChapterAll]>;
def FeatureCpu032II    : SubtargetFeature<"cpu032II", "Cpu0ArchVersion",
                               "Cpu032II", "Cpu032II ISA Support (slt)",
                                [FeatureCmp, FeatureSlt, FeatureChapterAll]>;

//===----------------------------------------------------------------------===//
// Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "Cpu0Schedule.td"
include "Cpu0InstrInfo.td"
include "Cpu0CallingConv.td"

/*  InstrInfo定义
    // InstrInfo - This class should only be instantiated once to provide parameters
    // which are global to the target machine.
    //
    class InstrInfo {
        // Target can specify its instructions in either big or little-endian formats.
        // For instance, while both Sparc and PowerPC are big-endian platforms, the
        // Sparc manual specifies its instructions in the format [31..0] (big), while
        // PowerPC specifies them using the format [0..31] (little).
        bit isLittleEndianEncoding = false;

        // The instruction properties mayLoad, mayStore, and hasSideEffects are unset
        // by default, and TableGen will infer their value from the instruction
        // pattern when possible.
        //
        // Normally, TableGen will issue an error it it can't infer the value of a
        // property that hasn't been set explicitly. When guessInstructionProperties
        // is set, it will guess a safe value instead.
        //
        // This option is a temporary migration help. It will go away.
        bit guessInstructionProperties = true;

        // TableGen's instruction encoder generator has support for matching operands
        // to bit-field variables both by name and by position. While matching by
        // name is preferred, this is currently not possible for complex operands,
        // and some targets still reply on the positional encoding rules. When
        // generating a decoder for such targets, the positional encoding rules must
        // be used by the decoder generator as well.
        //
        // This option is temporary; it will go away once the TableGen decoder
        // generator has better support for complex operands and targets have
        // migrated away from using positionally encoded operands.
        bit decodePositionallyEncodedOperands = false;

        // When set, this indicates that there will be no overlap between those
        // operands that are matched by ordering (positional operands) and those
        // matched by name.
        //
        // This option is temporary; it will go away once the TableGen decoder
        // generator has better support for complex operands and targets have
        // migrated away from using positionally encoded operands.
        bit noNamedPositionallyEncodedOperands = false;
    }
*/
def Cpu0InstrInfo : InstrInfo;
//===----------------------------------------------------------------------===//
// Cpu0 processors supported.
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, Cpu0GenericItineraries, Features>;

// 定义两种类型的芯片, 分别是 "cpu032I" 与 "cpu032II"
// "cpu032I"的特征是"FeatureCpu032I"
// "cpu032II"的特征是 "FeatureCpu032II"
def : Proc<"cpu032I",  [FeatureCpu032I]>;
def : Proc<"cpu032II", [FeatureCpu032II]>;
// Above make Cpu0GenSubtargetInfo.inc set feature bit as the following order
// enum {
//   FeatureCmp =  1ULL << 0,
//   FeatureCpu032I =  1ULL << 1,
//   FeatureCpu032II =  1ULL << 2,
//   FeatureSlt =  1ULL << 3
// };


/*  AsmParser定义
    //===----------------------------------------------------------------------===//
    // AsmParser - This class can be implemented by targets that wish to implement
    // .s file parsing.
    //
    // Subtargets can have multiple different assembly parsers (e.g. AT&T vs Intel
    // syntax on X86 for example).
    //
    class AsmParser {
        // AsmParserClassName - This specifies the suffix to use for the asmparser
        // class.  Generated AsmParser classes are always prefixed with the target
        // name.
        string AsmParserClassName  = "AsmParser";

        // AsmParserInstCleanup - If non-empty, this is the name of a custom member
        // function of the AsmParser class to call on every matched instruction.
        // This can be used to perform target specific instruction post-processing.
        string AsmParserInstCleanup  = "";

        // ShouldEmitMatchRegisterName - Set to false if the target needs a hand
        // written register name matcher
        bit ShouldEmitMatchRegisterName = true;

        // Set to true if the target needs a generated 'alternative register name'
        // matcher.
        //
        // This generates a function which can be used to lookup registers from
        // their aliases. This function will fail when called on targets where
        // several registers share the same alias (i.e. not a 1:1 mapping).
        bit ShouldEmitMatchRegisterAltName = false;

        // Set to true if MatchRegisterName and MatchRegisterAltName functions
        // should be generated even if there are duplicate register names. The
        // target is responsible for coercing aliased registers as necessary
        // (e.g. in validateTargetOperandClass), and there are no guarantees about
        // which numeric register identifier will be returned in the case of
        // multiple matches.
        bit AllowDuplicateRegisterNames = false;

        // HasMnemonicFirst - Set to false if target instructions don't always
        // start with a mnemonic as the first token.
        bit HasMnemonicFirst = true;

        // ReportMultipleNearMisses -
        // When 0, the assembly matcher reports an error for one encoding or operand
        // that did not match the parsed instruction.
        // When 1, the assembly matcher returns a list of encodings that were close
        // to matching the parsed instruction, so to allow more detailed error
        // messages.
        bit ReportMultipleNearMisses = false;
    }
*/
def Cpu0AsmParser : AsmParser {
  let ShouldEmitMatchRegisterName = 0;
}


/*  AsmParserVariant定义
    //===----------------------------------------------------------------------===//
    // AsmParserVariant - Subtargets can have multiple different assembly parsers
    // (e.g. AT&T vs Intel syntax on X86 for example). This class can be
    // implemented by targets to describe such variants.
    //
    class AsmParserVariant {
        // Variant - AsmParsers can be of multiple different variants.  Variants are
        // used to support targets that need to parse multiple formats for the
        // assembly language.
        int Variant = 0;

        // Name - The AsmParser variant name (e.g., AT&T vs Intel).
        string Name = "";

        // CommentDelimiter - If given, the delimiter string used to recognize
        // comments which are hard coded in the .td assembler strings for individual
        // instructions.
        string CommentDelimiter = "";

        // RegisterPrefix - If given, the token prefix which indicates a register
        // token. This is used by the matcher to automatically recognize hard coded
        // register tokens as constrained registers, instead of tokens, for the
        // purposes of matching.
        string RegisterPrefix = "";

        // TokenizingCharacters - Characters that are standalone tokens
        string TokenizingCharacters = "[]*!";

        // SeparatorCharacters - Characters that are not tokens
        string SeparatorCharacters = " \t,";

        // BreakCharacters - Characters that start new identifiers
        string BreakCharacters = "";
    }
*/
def Cpu0AsmParserVariant : AsmParserVariant {
  int Variant = 0;                                                                        // 设置有几种汇编格式

  // Recognize hard coded registers.
  string RegisterPrefix = "$";                                                            // 设置寄存器的起始标志
}


/*  Target定义
    class Target {
        // InstructionSet - Instruction set description for this target.
        InstrInfo InstructionSet;

        // AssemblyParsers - The AsmParser instances available for this target.
        list<AsmParser> AssemblyParsers = [DefaultAsmParser];

        /// AssemblyParserVariants - The AsmParserVariant instances available for
        /// this target.
        list<AsmParserVariant> AssemblyParserVariants = [DefaultAsmParserVariant];

        // AssemblyWriters - The AsmWriter instances available for this target.
        list<AsmWriter> AssemblyWriters = [DefaultAsmWriter];

        // AllowRegisterRenaming - Controls whether this target allows
        // post-register-allocation renaming of registers.  This is done by
        // setting hasExtraDefRegAllocReq and hasExtraSrcRegAllocReq to 1
        // for all opcodes if this flag is set to 0.
        int AllowRegisterRenaming = 0;
    }
 */

// Will generate Cpu0GenAsmWrite.inc included by Cpu0InstPrinter.cpp, contents
//  as follows,
// void Cpu0InstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char *Cpu0InstPrinter::getRegisterName(unsigned RegNo) {...}

// 在此处定义一个后端生成目标名称
def Cpu0 : Target {
// def Cpu0InstrInfo : InstrInfo as before.
  let InstructionSet = Cpu0InstrInfo;                                                     // 设置指令集
  let AssemblyParsers = [Cpu0AsmParser];                                                  // 设置默认汇编分析器
  let AssemblyParserVariants = [Cpu0AsmParserVariant];                                    // 设置有几种汇编格式
}

