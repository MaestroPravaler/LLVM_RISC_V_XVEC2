//===-- RISCVXVEC2TargetInfo.cpp - RISCVXVEC2 Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

namespace llvm {
Target &getTheRISCVXVEC32Target() {
  static Target TheRISCVXVEC32Target;
  return TheRISCVXVEC32Target;
}

Target &getTheRISCVXVEC64Target() {
  static Target TheRISCVXVEC64Target;
  return TheRISCVXVEC64Target;
}
}

extern "C" void LLVMInitializeRISCVXVEC2TargetInfo() {
  RegisterTarget<Triple::riscvxvec32> X(getTheRISCVXVEC32Target(), "riscvxvec32",
                                    "32-bit riscvxvec32");
  RegisterTarget<Triple::riscvxvec64> Y(getTheRISCVXVEC64Target(), "riscvxvec64",
                                    "64-bit riscvxvec32");
}
