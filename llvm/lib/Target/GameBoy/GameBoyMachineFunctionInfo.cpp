#include "GameBoyMachineFunctionInfo.h"

using namespace llvm;

void GameBoyMachineFunctionInfo::anchor() {}

MachineFunctionInfo *GameBoyMachineFunctionInfo::clone(
    BumpPtrAllocator &Allocator, MachineFunction &DestMF,
    const DenseMap<MachineBasicBlock *, MachineBasicBlock *> &Src2DstMBB)
    const {
  return DestMF.cloneInfo<GameBoyMachineFunctionInfo>(*this);
}