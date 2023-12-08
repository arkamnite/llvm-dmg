#ifndef LLVM_GAMEBOY_H
#define LLVM_GAMEBOY_H

#include "llvm/CodeGen/SelectionDAGNodes.h"
#include "llvm/Pass.h"
#include "llvm/PassRegistry.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class GameBoyTargetMachine;
class FunctionPass;
class PassRegistry;

Pass *createGameBoyShiftExpandPass();
FunctionPass *createGameBoyISelDag(GameBoyTargetMachine &TM,
                               CodeGenOpt::Level OptLevel);
FunctionPass *createGameBoyExpandPseudoPass();
FunctionPass *createGameBoyFrameAnalyzerPass();
FunctionPass *createGameBoyBranchSelectionPass();

void initializeGameBoyDAGToDAGISelPass(PassRegistry &);
void initializeGameBoyExpandPseudoPass(PassRegistry &);
void initializeGameBoyShiftExpandPass(PassRegistry &);

} // end namespace llvm

#endif // LLVM_GAMEBOY_H