//===-- RISCVXVEC2MCTargetDesc.cpp - RISCVXVEC2 Target Descriptions -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// This file provides RISCVXVEC2-specific target descriptions.
///
//===----------------------------------------------------------------------===//

#include "RISCVXVEC2MCTargetDesc.h"
#include "RISCVXVEC2MCAsmInfo.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "RISCVXVEC2GenInstrInfo.inc"

#define GET_REGINFO_MC_DESC
#include "RISCVXVEC2GenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createRISCVXVEC2MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitRISCVXVEC2MCInstrInfo(X);
  return X;
}
/*
static MCRegisterInfo *createRISCVXVEC2MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitRISCVXVEC2MCRegisterInfo(X, RISCVXVEC2::X1_32);
  return X;
}  erro X1_32 não perence ao llvm:RISCVXVEC2*/

static MCAsmInfo *createRISCVXVEC2MCAsmInfo(const MCRegisterInfo &MRI,
                                       const Triple &TT) {
  return new RISCVXVEC2MCAsmInfo(TT);
}

extern "C" void LLVMInitializeRISCVXVEC2TargetMC() {
  for (Target *T : {&getTheRISCVXVEC32Target(), &getTheRISCVXVEC64Target()}) {
    TargetRegistry::RegisterMCAsmInfo(*T, createRISCVXVEC2MCAsmInfo);
    TargetRegistry::RegisterMCInstrInfo(*T, createRISCVXVEC2MCInstrInfo);
    // TargetRegistry::RegisterMCRegInfo(*T, createRISCVXVEC2MCRegisterInfo);
    TargetRegistry::RegisterMCAsmBackend(*T, createRISCVXVEC2AsmBackend);
    TargetRegistry::RegisterMCCodeEmitter(*T, createRISCVXVEC2MCCodeEmitter);
  }
}
