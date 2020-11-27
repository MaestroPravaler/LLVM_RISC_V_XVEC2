//===-- RISCVXVEC2InstrInfo.td - Target Description for RISCVXVEC2 ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file describes the RISC-V instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

include "RISCVXVEC2InstrFormats.td"

def simm12 : Operand<i32>;

// As noted in RISCVXVEC2RegisterInfo.td, the hope is that support for
// variable-sized register classes will mean that instruction definitions do
// not need to be duplicated for 32-bit and 64-bit register classes. For now
// we use 'GPR', which is 32-bit. When codegen for both RV32 and RV64 is
// added, we will need to duplicate instruction definitions unless a proposal
// like <http://lists.llvm.org/pipermail/llvm-dev/2016-September/105027.html>
// is adopted.

class ALU_ri<bits<3> funct3, string OpcodeStr> :
      FI<funct3, 0b0010011, (outs GPR:$rd), (ins GPR:$rs1, simm12:$imm12),
         OpcodeStr#"\t$rd, $rs1, $imm12", []>
{
}

def ADDI  : ALU_ri<0b000, "addi">;
def SLTI  : ALU_ri<0b010, "slti">;
def SLTIU : ALU_ri<0b011, "sltiu">;
def XORI  : ALU_ri<0b100, "xori">;
def ORI   : ALU_ri<0b110, "ori">;
def ANDI  : ALU_ri<0b111, "andi">;

class ALU_rr<bits<7> funct7, bits<3> funct3, string OpcodeStr> :
      FR<funct7, funct3, 0b0110011, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
         OpcodeStr#"\t$rd, $rs1, $rs2", []>
{
}

def ADD  : ALU_rr<0b0000000, 0b000, "add">;
def SUB  : ALU_rr<0b0100000, 0b000, "sub">;
def SLL  : ALU_rr<0b0000000, 0b001, "sll">;
def SLT  : ALU_rr<0b0000000, 0b010, "slt">;
def SLTU : ALU_rr<0b0000000, 0b011, "sltu">;
def XOR  : ALU_rr<0b0000000, 0b100, "xor">;
def SRL  : ALU_rr<0b0000000, 0b101, "srl">;
def SRA  : ALU_rr<0b0100000, 0b101, "sra">;
def OR   : ALU_rr<0b0000000, 0b110, "or">;
def AND  : ALU_rr<0b0000000, 0b111, "and">;



//===----------------------------------------------------------------------===//
// Instruction Class Templates XVEC2
//===----------------------------------------------------------------------===//

class ALU_riv<bits<3> funct3, string OpcodeStr> :
		FI<funct3, 0b1011011, (outs GPR:$rd), (ins GPR:$rs1, simm12:$imm12),
        	OpcodeStr#"\t$rd, $rs1, $imm12", []>
{
}

class ALU_rrv<bits<7> funct7, bits<3> funct3, string OpcodeStr> :
		FR<funct7, funct3, 0b1111011, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
        	OpcodeStr#"\t$rd, $rs1, $rs2", []>
{
}

class Load_riv<bits<3> funct3, string OpcodeStr> :
		FI<funct3, 0b0001011, (outs GPR:$rd), (ins GPR:$rs1, simm12:$imm12),
        	OpcodeStr#"\t$rd, $imm12¸$rs1", []>
{
}

class Store_rriv<bits<3> funct3, string OpcodeStr> : 
		FS<funct3, 0b0101011, (outs), (ins GPR:$rs2, GPR:$rs1, simm12:$imm12),
        	OpcodeStr#"\t$rs2, $imm12, $rs1", []>
{
}

/* class Shift_riv<bit arithshift, bits<3> funct3, string OpcodeStr> :
		 FI32Shift<arithshift, funct3, 0b1011011, (outs GPR:$rd), (ins GPR:$rs1, uimmlog2xlen:$shamt), 
        	OpcodeStr#"\$rd, $rs1, $shamt", []> 
{
} error: Variable not defined: 'uimmlog2xlen' */

//===----------------------------------------------------------------------===//
// (Register-)Immediate arith operations XVEC2
//===----------------------------------------------------------------------===//
def ADDIV  : ALU_riv<0b000, "addiv">;
def SLTIV  : ALU_riv<0b010, "sltiv">;
def SLTIUV : ALU_riv<0b011, "sltiuv">;
def XORIV  : ALU_riv<0b100, "xoriv">;
def ORIV   : ALU_riv<0b110, "oriv">;
def ANDIV  : ALU_riv<0b111, "andiv">;

/* ====+++++
A função esta acima comentada assim não funcionara estas implementações

def SLLIV : Shift_riv<0, 0b001, "slliv">;
def SRLIV : Shift_riv<0, 0b101, "srliv">;
def SRAIV : Shift_riv<1, 0b101, "sraiv">;

*/

//===----------------------------------------------------------------------===//
// Register-register arith operations XVEC2
//===----------------------------------------------------------------------===//
def ADDV  : ALU_rrv<0b0000000, 0b000, "addv">;
def SUBV  : ALU_rrv<0b0100000, 0b000, "subv">;
def SLLV  : ALU_rrv<0b0000000, 0b001, "sllv">;
def SLTV  : ALU_rrv<0b0000000, 0b010, "sltv">;
def SLTUV : ALU_rrv<0b0000000, 0b011, "sltuv">;
def XORV  : ALU_rrv<0b0000000, 0b100, "xorv">;
def SRLV  : ALU_rrv<0b0000000, 0b101, "srlv">;
def SRAV  : ALU_rrv<0b0100000, 0b101, "srav">;
def ORV   : ALU_rrv<0b0000000, 0b110, "orv">;
def ANDV  : ALU_rrv<0b0000000, 0b111, "andv">;




//===----------------------------------------------------------------------===//
// LOAD / STORE XVEC2
//===----------------------------------------------------------------------===//
def LBV  : Load_riv<0b000, "lbv">;
def LHV  : Load_riv<0b001, "lhv">;
def LWV  : Load_riv<0b010, "lwv">;
def LBUV : Load_riv<0b100, "lbuv">;
def LHUV : Load_riv<0b101, "lhuv">;

def SBV : Store_rriv<0b000, "sbv">;
def SHV : Store_rriv<0b001, "shv">;
def SWV : Store_rriv<0b010, "swv">;

//===----------------------------------------------------------------------===//