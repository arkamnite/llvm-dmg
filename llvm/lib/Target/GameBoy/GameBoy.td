include "llvm/Target/Target.td"

//===
// Register File, Calling Conv, Instruction Descriptions
//===

include "GameBoyRegisterInfo.td"
include "GameBoyInstrInfo.td"

def GameBoyInstrInfo : InstrInfo;

//===
// Declare our target
//===

def GameBoy : Target {
    // Pull in instruction info when ready.
    let InstructionSet = GameBoyInstrInfo;
}