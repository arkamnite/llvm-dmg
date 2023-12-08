add_llvm_component_group(GameBoy)

set(LLVM_TARGET_DEFINITIONS GameBoy.td)

tablegen(LLVM GameBoyGenAsmMatcher.inc -gen-asm-matcher)
tablegen(LLVM GameBoyGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM GameBoyGenCallingConv.inc -gen-callingconv)
tablegen(LLVM GameBoyGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM GameBoyGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GameBoyGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GameBoyGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(GameBoyCommonTableGen)

add_llvm_target(GameBoyCodeGen
    GameBoyFrameLowering.cpp
    GameBoyInstrInfo.cpp
    GameBoyISelLowering.cpp
    GameBoyMachineFunctionInfo.cpp
    GameBoyRegisterInfo.cpp
    GameBoySubtarget.cpp
    GameBoyTargetMachine.cpp

    LINK_COMPONENTS
    AsmPrinter
    CodeGen
    CodeGenTypes
    Core
    MC
    SelectionDAG
    GameBoyDesc
    GameBoyInfo
    Support
    Target
    TargetParser

    ADD_TO_COMPONENT
    GameBoy
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)