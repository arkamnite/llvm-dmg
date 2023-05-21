add_llvm_component_group(GameBoy)

set(LLVM_TARGET_DEFINITIONS GameBoy.td)

tablegen(LLVM GameBoyGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GameBoyGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GameBoyGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(GameBoyCommonTableGen)

add_llvm_target(GameBoyCodeGen

    GameBoyTargetMachine.cpp
    GameBoyInstrInfo.cpp
    GameBoyRegisterInfo.cpp
    GameBoyMachineFunctionInfo.cpp


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