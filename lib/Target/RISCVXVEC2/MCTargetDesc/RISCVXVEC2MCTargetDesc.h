//===-- RISCVXVEC2MCTargetDesc.h - RISCVXVEC2 Target Descriptions ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides RISCVXVEC2 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_RISCVXVEC2_MCTARGETDESC_RISCVXVEC2MCTARGETDESC_H
#define LLVM_LIB_TARGET_RISCVXVEC2_MCTARGETDESC_RISCVXVEC2MCTARGETDESC_H

#include "llvm/Config/config.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/DataTypes.h"

namespace llvm {
class MCAsmBackend;
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCObjectWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class StringRef;
class Target;
class Triple;
class raw_ostream;
class raw_pwrite_stream;

Target &getTheRISCVXVEC32Target();
Target &getTheRISCVXVEC64Target();

MCCodeEmitter *createRISCVXVEC2MCCodeEmitter(const MCInstrInfo &MCII,
                                        const MCRegisterInfo &MRI,
                                        MCContext &Ctx);

MCAsmBackend *createRISCVXVEC2AsmBackend(const Target &T, const MCRegisterInfo &MRI,
                                    const Triple &TT, StringRef CPU,
                                    const MCTargetOptions &Options);

MCObjectWriter *createRISCVXVEC2ELFObjectWriter(raw_pwrite_stream &OS, uint8_t OSABI,
                                           bool Is64Bit);
}

// Defines symbolic names for RISC-V registers.
#define GET_REGINFO_ENUM
#include "RISCVXVEC2GenRegisterInfo.inc"

// Defines symbolic names for RISC-V instructions.
#define GET_INSTRINFO_ENUM
#include "RISCVXVEC2GenInstrInfo.inc"

#endif
