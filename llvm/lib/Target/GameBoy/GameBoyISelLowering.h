#ifndef LLVM_GAMEBOY_ISEL_LOWERING_H
#define LLVM_GAMEBOY_ISEL_LOWERING_H

#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class GameBoySubtarget;
class GameBoyTargetMachine;

class GameBoyTargetLowering : public TargetLowering {
public:
  explicit GameBoyTargetLowering(const GameBoyTargetMachine &TM,
                             const GameBoySubtarget &STI);
  
};
} // end namespace llvm

#endif // LLVM_GAMEBOY_ISEL_LOWERING_H