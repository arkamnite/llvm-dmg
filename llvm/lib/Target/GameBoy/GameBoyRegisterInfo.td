class GameBoyReg<bits<16> num, 
                 string name, 
                 list<Register> subregs=[]> : RegisterWithSubRegs<name, subregs> 
{
    field bits<16> Num = num;

    let HWEncoding = num;
    let Namespace = "GameBoy";
    let SubRegs = subregs;
    let AltNames = [];
}

// Subregister indices
let Namespace = "GameBoy" in {
    def sub_lo : SubRegIndex<8>;
    def sub_hi : SubRegIndex<8, 8>;
}

let Namespace = "GameBoy" in { def ptr : RegAltNameIndex; }

// 8-bit GPIO registers A through F
def RA : GameBoyReg<0, "a">, DwarfRegNum<[0]>;

// 8-bit register classes
def GPR : RegisterClass<"GameBoy", [i8], 8, (add RA)>;