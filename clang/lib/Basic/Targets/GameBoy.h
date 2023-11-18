#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_GAMEBOY_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_GAMEBOY_H

#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/TargetParser/Triple.h"
#include "llvm/Support/Compiler.h"

namespace clang {
namespace targets {

class LLVM_LIBRARY_VISIBILITY GameBoyTargetInfo : public TargetInfo {
public:
    static const char *const GCCRegNames[];

    GameBoyTargetInfo(const llvm::Triple &Triple, const TargetOptions &Options) : TargetInfo(Triple) {
        // "e-p:16:8-i8:8-i16:16-i32:16-i64:16-f32:8-f64:8-n8-a:8";
        SuitableAlign = 16;
        WCharType = SignedInt;
        WIntType = UnsignedInt;
        IntPtrType = SignedInt;
        PtrDiffType = SignedInt;
        SizeType = UnsignedInt;
    }

    ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override;
    
    void getTargetDefines(const LangOptions &Opts, MacroBuilder &Builder) const override;

    ArrayRef<const char *> getGCCRegNames() const override;

    std::string_view getClobbers() const override;

    ArrayRef<Builtin::Info> getTargetBuiltins() const override;

    BuiltinVaListKind getBuiltinVaListKind() const override {
        return TargetInfo::VoidPtrBuiltinVaList;
    }

    bool validateAsmConstraint(const char *&Name,
                             TargetInfo::ConstraintInfo &Info) const override {
        return false;
    }
};

} // targets
} // clang

#endif // LLVM_CLANG_LIB_BASIC_TARGETS_GAMEBOY_H