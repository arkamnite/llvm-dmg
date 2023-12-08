#include "GameBoyFrameLowering.h"

#include "GameBoy.h"
#include "GameBoyInstrInfo.h"
#include "GameBoyMachineFunctionInfo.h"
#include "GameBoyTargetMachine.h"
#include "MCTargetDesc/GameBoyMCTargetDesc.h"

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/IR/Function.h"

#include <vector>

namespace llvm {

GameBoyFrameLowering::GameBoyFrameLowering()
    : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(1), -2) {}

bool GameBoyFrameLowering::canSimplifyCallFramePseudos(
    const MachineFunction &MF) const {
  // Always simplify call frame pseudo instructions, even when
  // hasReservedCallFrame is false.
  return true;
}
} // end namespace llvm