//===-- RISCVXVEC2ELFObjectWriter.cpp - RISCVXVEC2 ELF Writer -----------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/RISCVXVEC2MCTargetDesc.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCFixup.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class RISCVXVEC2ELFObjectWriter : public MCELFObjectTargetWriter {
public:
  RISCVXVEC2ELFObjectWriter(uint8_t OSABI, bool Is64Bit);

  ~RISCVXVEC2ELFObjectWriter() override;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;
};
}

RISCVXVEC2ELFObjectWriter::RISCVXVEC2ELFObjectWriter(uint8_t OSABI, bool Is64Bit)
    : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_RISCVXVEC2,
                              /*HasRelocationAddend*/ false) {}

RISCVXVEC2ELFObjectWriter::~RISCVXVEC2ELFObjectWriter() {}

unsigned RISCVXVEC2ELFObjectWriter::getRelocType(MCContext &Ctx,
                                            const MCValue &Target,
                                            const MCFixup &Fixup,
                                            bool IsPCRel) const {
  llvm_unreachable("invalid fixup kind!");
}

MCObjectWriter *llvm::createRISCVXVEC2ELFObjectWriter(raw_pwrite_stream &OS,
                                                 uint8_t OSABI, bool Is64Bit) {
  MCELFObjectTargetWriter *MOTW = new RISCVXVEC2ELFObjectWriter(OSABI, Is64Bit);
  return createELFObjectWriter(MOTW, OS, /*IsLittleEndian*/ true);
}
