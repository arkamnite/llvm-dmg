#include "GameBoyMCTargetDesc.h"
#include "TargetInfo/GameBoyTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#define ENABLE_INSTR_PREDICATE_VERIFIER
#include "GameBoyGenInstrInfo.inc"

// #define GET_SUBTARGETINFO_MC_DESC
// #include "GameBoyGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "GameBoyGenRegisterInfo.inc"

// static MCInstrInfo *createGameBoyMCInstrInfo() {
//     MCInstrInfo *X = new MCInstrInfo();
//     InitGameBoyMCInstrInfo(X);
// }

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGameBoyTargetMC() {
    // Register the MC asm info.

    for (Target *T :
        {&getTheGameBoyTarget()}) {

    // Register MC instruction info.
    // Register MC register info.
    // Register MC subtarget info.
    // Register MC Code Emitter.
    // Register the asm backend.
    // Register the object target streamer.
    // Register the asm streamer.
    // Register the null streamer.
    // Register the MCInstPrinter.
    }
}
