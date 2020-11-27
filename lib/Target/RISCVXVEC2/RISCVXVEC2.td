//===-- RISCVXVEC2.td - Describe the RISCVXVEC2 Target Machine -------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

include "RISCVXVEC2RegisterInfo.td"
include "RISCVXVEC2InstrInfo.td"


def RISCVXVEC2InstrInfo : InstrInfo;

def Feature64Bit   : SubtargetFeature<"64bit", "HasRV64", "true",
                                      "Implements RV64">;

def : ProcessorModel<"generic-rv32", NoSchedModel, []>;

def : ProcessorModel<"generic-rv64", NoSchedModel, [Feature64Bit]>;

def RISCVXVEC2 : Target {
  let InstructionSet = RISCVXVEC2InstrInfo;
}
