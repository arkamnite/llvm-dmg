#include "GameBoy.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "llvm/ADT/StringSwitch.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

const char *const GameBoyTargetInfo::GCCRegNames[] = {
    "a", "b", "c", "d", "h", "l", "f", "sp", "pc",
};

const TargetInfo::GCCRegAlias GCCRegAliases[] = {
    {{"accumulator"}, "a"},
     {{"b"}, "b"},
     {{"c"}, "c"},
     {{"d"}, "d"},
     {{"h"}, "h"},
     {{"l"}, "l"},
     {{"flags"}, "f"},
     {{"pc"}, "pc"},
     {{"sp"}, "sp"}
};

ArrayRef<const char*> GameBoyTargetInfo::getGCCRegNames() const {
    return llvm::makeArrayRef(GCCRegNames);
}

ArrayRef<TargetInfo::GCCRegAlias> GameBoyTargetInfo::getGCCRegAliases() const {
    return llvm::makeArrayRef(GCCRegAliases);
}

 void GameBoyTargetInfo::getTargetDefines(   const LangOptions &Opts,
                                             MacroBuilder &Builder) const {
         // Define the __GAMEBOY__ macro when building for this target
         Builder.defineMacro("__GAMEBOY__");
}

std::string_view GameBoyTargetInfo::getClobbers() const {
    return "";
}

ArrayRef<Builtin::Info> GameBoyTargetInfo::getTargetBuiltins() const {
    return std::nullopt;
}