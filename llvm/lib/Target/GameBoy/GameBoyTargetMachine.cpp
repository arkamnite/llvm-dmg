#include "GameBoyTargetMachine.h"
#include "TargetInfo/GameBoyTargetInfo.h"
#include "GameBoyMachineFunctionInfo.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"

#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

namespace llvm {

static const char *GameBoyDataLayout =
    "e-p:16:8-i8:8-i16:16-i32:16-i64:16-f32:8-f64:8-n8-a:8";


GameBoyTargetMachine::GameBoyTargetMachine( const Target &T, const Triple &TT,
                      StringRef CPU, StringRef FS,
                      const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM,
                      CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T, GameBoyDataLayout, TT, CPU, FS, Options,
                        RM.value_or(Reloc::Static),
                        getEffectiveCodeModel(CM, CodeModel::Small),
                        OL),
    TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
    SubTarget(TT, std::string(CPU), std::string(FS), *this, false)
{

}

GameBoyTargetMachine::~GameBoyTargetMachine() = default;

MachineFunctionInfo *GameBoyTargetMachine::createMachineFunctionInfo(
  BumpPtrAllocator &Allocator, const Function &F,
  const TargetSubtargetInfo *STI) const {

  return GameBoyMachineFunctionInfo::create<GameBoyMachineFunctionInfo>(Allocator, F, STI);
}

namespace {
/// Game Boy Code Generator Pass Configuration Options
class GameBoyPassConfig : public TargetPassConfig {

  public:
  GameBoyPassConfig(GameBoyTargetMachine &TM, PassManagerBase &PM) : TargetPassConfig(TM, PM) {}

  GameBoyTargetMachine &getGameBoyTargetMachine() const {
    return getTM<GameBoyTargetMachine>();
  }
  
  // Add various overrides for passes that should be added here.

};
} // namespace

TargetPassConfig *GameBoyTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new GameBoyPassConfig(*this, PM);
}


extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGameBoyTarget() {
  // Register the target
  RegisterTargetMachine<GameBoyTargetMachine> X(getTheGameBoyTarget());

  // TODO: Enable this pass.
  PassRegistry &PR = *PassRegistry::getPassRegistry();
  initializeGameBoyExpandPseudoPass(PR);
  initializeGameBoyShiftExpandPass(PR);
  initializeGameBoyDAGToDAGISelPass(PR);
}

} // end namespace llvm