//===-- RISCVXVEC2MCAsmInfo.cpp - RISCVXVEC2 Asm properties -------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the RISCVXVEC2MCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "RISCVXVEC2MCAsmInfo.h"
#include "llvm/ADT/Triple.h"
using namespace llvm;

void RISCVXVEC2MCAsmInfo::anchor() {}

RISCVXVEC2MCAsmInfo::RISCVXVEC2MCAsmInfo(const Triple &TT) {
  CodePointerSize = CalleeSaveStackSlotSize = TT.isArch64Bit() ? 8 : 4;
  CommentString = "#";
  AlignmentIsInBytes = false;
  SupportsDebugInformation = true;
}
