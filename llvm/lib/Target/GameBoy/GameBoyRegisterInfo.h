#ifndef LLVM_LIB_TARGET_GAMEBOY_GAMEBOYREGISTERINFO_H
#define LLVM_LIB_TARGET_GAMEBOY_GAMEBOYREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "GameBoyGenRegisterInfo.inc"

namespace llvm {

struct GameBoyRegisterInfo : public GameBoyGenRegisterInfo {
    GameBoyRegisterInfo();

    // Codegen virtual methods...
};

} // end namespace llvm

#endif