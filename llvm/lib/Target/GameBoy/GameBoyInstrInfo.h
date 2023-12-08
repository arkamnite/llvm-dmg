#ifndef LLVM_GAMEBOY_INSTR_INFO_H
#define LLVM_GAMEBOY_INSTR_INFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"
#include "GameBoyRegisterInfo.h"

#define GET_INSTRINFO_HEADER
#include "GameBoyGenInstrInfo.inc"
#undef GET_INSTRINFO_HEADER

namespace llvm {

class GameBoyInstrInfo : public GameBoyGenInstrInfo {
public:
    explicit GameBoyInstrInfo();

    const GameBoyRegisterInfo &getRegisterInfo() const { return RI; }

private:
    GameBoyRegisterInfo RI;
};

} // end namespace llvm

#endif // LLVM_GAMEBOY_INSTR_INFO_H