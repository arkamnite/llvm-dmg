#ifndef LLVM_LIB_TARGET_GAMEBOY_MCTARGETDESC_GAMEBOYMCTARGETDESC_H
#define LLVM_LIB_TARGET_GAMEBOY_MCTARGETDESC_GAMEBOYMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

namespace llvm
{
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;
} // namespace llvm

// Define symbolic names for Game Boy registers; maps names to numbers for registers.
#define GET_REGINFO_ENUM
#include "GameBoyGenRegisterInfo.inc"

// Define symbolic names for the Game Boy ISA.
#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "GameBoyGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "GameBoyGenSubtargetInfo.inc"

#endif // LLVM_LIB_TARGET_GAMEBOY_MCTARGETDESK_GAMEBOYMCTARGETDESC_H