#ifndef LLVM_LIB_TARGET_GAMEBOY_GAMEBOYTARGETMACHINE_H
#define LLVM_LIB_TARGET_GAMEBOY_GAMEBOYTARGETMACHINE_H

#include "GameBoySubtarget.h"
#include "llvm/Target/TargetMachine.h"
#include <optional>

namespace llvm {

class GameBoyTargetMachine : public LLVMTargetMachine {
public:
    GameBoyTargetMachine( const Target &T, const Triple &TT,
                      StringRef CPU, StringRef FS,
                      const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM,
                      CodeGenOpt::Level OL, bool JIT);
    
    ~GameBoyTargetMachine() override;

    const GameBoySubtarget *getSubtargetImpl() const;
    const GameBoySubtarget *getSubtargetImpl(const Function &) const override;

    // Pass pipeline configuration
    TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
    TargetLoweringObjectFile *getObjFileLowering() const override {
        return TLOF.get();
    }

    MachineFunctionInfo *
    createMachineFunctionInfo(BumpPtrAllocator &Allocator, const Function &F,
                              const TargetSubtargetInfo *STI) const override;

private:
    std::unique_ptr<TargetLoweringObjectFile> TLOF;
    GameBoySubtarget SubTarget;
};

} // end namespace llvm

#endif