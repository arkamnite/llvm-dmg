#include "TargetInfo/GameBoyTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheGameBoyTarget() {
    static Target TheGameBoyTarget;
    return TheGameBoyTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGameBoyTargetInfo() {
    RegisterTarget<Triple::gameboy, /*HasJIT=*/false> X(getTheGameBoyTarget(), "gameboy", "Nintendo Game Boy", "GAME BOY");
}