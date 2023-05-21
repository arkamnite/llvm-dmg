add_llvm_component_library(LLVMGameBoyDesc
    # TODO: Create files/stubs object writers.
    # GameBoyAsmBackend.cpp
    # GameBoyDMGObjectWriter.cpp
    # GameBoyRGBASMObjectWriter.cpp
    # GameBoyMCAsmInfo.cpp
    # GameBoyInstPrinter.cpp
    # GameBoyMCCodeEmitter.cpp
    GameBoyMCTargetDesc.cpp    
    # GameBoyTargetStreamer.cpp

    LINK_COMPONENTS
    MC
    GameBoyInfo
    Support
    TargetParser

    ADD_TO_COMPONENT
    GameBoy
)