#include "GameBoyRegisterInfo.h"

#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/IR/Function.h"

#include "GameBoy.h"
#include "GameBoyInstrInfo.h"
#include "GameBoyMachineFunctionInfo.h"
#include "GameBoyTargetMachine.h"
#include "MCTargetDesc/GameBoyMCTargetDesc.h"

#define GET_REGINFO_TARGET_DESC
#include "GameBoyGenRegisterInfo.inc"

namespace llvm {

GameBoyRegisterInfo::GameBoyRegisterInfo() : GameBoyGenRegisterInfo(0) {}

}