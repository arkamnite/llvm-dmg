#ifndef LLVM_LIB_TARGET_GAMEBOY_GAMEBOYMACHINEFUNCTIONINFO_H
#define LLVM_LIB_TARGET_GAMEBOY_GAMEBOYMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {
  class GameBoyMachineFunctionInfo : public MachineFunctionInfo {
    virtual void anchor();
  private:
    Register GlobalBaseReg;
  public:
    GameBoyMachineFunctionInfo() : GlobalBaseReg(0) {}
    GameBoyMachineFunctionInfo(const Function &F, const TargetSubtargetInfo *STI)
        : GlobalBaseReg(0) {}

    MachineFunctionInfo *
    clone(BumpPtrAllocator &Allocator, MachineFunction &DestMF,
        const DenseMap<MachineBasicBlock *, MachineBasicBlock *> &Src2DstMBB)
      const override;

  };
}

#endif // LLVM_LIB_TARGET_GAMEBOY_GAMEBOYMACHINEFUNCTIONINFO_H