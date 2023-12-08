#include "GameBoySubtarget.h"
#include "GameBoy.h"
#include "MCTargetDesc/GameBoyMCTargetDesc.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "GameBoyGenSubtargetInfo.inc"

namespace llvm {

GameBoySubtarget::GameBoySubtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const GameBoyTargetMachine &TM)
    : GameBoyGenSubtargetInfo(TT, CPU, /*TuneCPU*/ CPU, FS),
      TLInfo(TM, initializeSubtargetDependencies(CPU, FS, TM)) {
  // Parse features string.
  ParseSubtargetFeatures(CPU, /*TuneCPU*/ CPU, FS);
}

GameBoySubtarget &
GameBoySubtarget::initializeSubtargetDependencies(StringRef CPU, StringRef FS,
                                              const TargetMachine &TM) {
  // Parse features string.
  ParseSubtargetFeatures(CPU, /*TuneCPU*/ CPU, FS);
  return *this;
}

} // end of namespace llvm