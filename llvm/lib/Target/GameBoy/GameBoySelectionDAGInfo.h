#ifndef LLVM_GAMEBOY_SELECTION_DAG_INFO_H
#define LLVM_GAMEBOY_SELECTION_DAG_INFO_H

#include "llvm/CodeGen/SelectionDAGTargetInfo.h"

namespace llvm {

/// Holds information about the GameBoy instruction selection DAG.
class GameBoySelectionDAGInfo : public SelectionDAGTargetInfo {
public:
};

} // end namespace llvm

#endif // LLVM_GAMEBOY_SELECTION_DAG_INFO_H