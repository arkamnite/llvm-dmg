#include "GameBoyISelLowering.h"

#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/ErrorHandling.h"

#include "GameBoy.h"
#include "GameBoyMachineFunctionInfo.h"
#include "GameBoySubtarget.h"
#include "GameBoyTargetMachine.h"
#include "MCTargetDesc/GameBoyMCTargetDesc.h"

namespace llvm {

GameBoyTargetLowering::GameBoyTargetLowering(const GameBoyTargetMachine &TM,
                                             const GameBoySubtarget &STI)
        : TargetLowering(TM), Subtarget(STI) {

    }

} // end namespace llvm