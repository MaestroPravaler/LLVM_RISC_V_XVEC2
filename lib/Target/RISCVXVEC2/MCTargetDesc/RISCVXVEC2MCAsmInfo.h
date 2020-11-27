//===-- RISCVXVEC2MCAsmInfo.h - RISCVXVEC2 Asm Info ----------------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the RISCVXVEC2MCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_RISCVXVEC2_MCTARGETDESC_RISCVXVEC2MCASMINFO_H
#define LLVM_LIB_TARGET_RISCVXVEC2_MCTARGETDESC_RISCVXVEC2MCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
class Triple;

class RISCVXVEC2MCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit RISCVXVEC2MCAsmInfo(const Triple &TargetTriple);
};

} // namespace llvm

#endif
