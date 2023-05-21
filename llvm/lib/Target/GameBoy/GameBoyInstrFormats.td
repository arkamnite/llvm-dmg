///====
// Generic Game Boy instruction classes
///====

class GameBoyInst<dag outs, dag ins, string asmstr, list<dag> pattern> : Instruction {
    let Namespace = "GameBoy";

    dag OutOperandList = outs;
    dag InOperandList = ins;
    let AsmString = asmstr;
    let Pattern = pattern;

    field bits<32> SoftFail = 0;
}

/// An 8-bit GameBoy instruction.
class GameBoyInst8<dag outs, dag ins, string asmstr, list<dag> pattern>
    : GameBoyInst<outs, ins, asmstr, pattern> {

    field bits<8> Inst;
    let Size = 1;
}

/// An 8-bit Pseudo instruction.
class PseudoInst8<dag outs, dag ins, string asmstr, list<dag> pattern>
    : GameBoyInst8<outs, ins, asmstr, pattern> {
    let Pattern = pattern;

    let isPseudo = 1;
    let isCodeGenOnly = 1;
}

///====
/// Game Boy Specific Instruction Formats
///====

/// Format 0
class GBF0<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern>
: GameBoyInst8<outs, ins, asmstr, pattern> {
    let Inst = op;
}
