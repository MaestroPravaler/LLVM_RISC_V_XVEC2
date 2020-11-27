set(LLVM_TARGET_DEFINITIONS RISCVXVEC2.td)

tablegen(LLVM RISCVXVEC2GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM RISCVXVEC2GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM RISCVXVEC2GenMCCodeEmitter.inc -gen-emitter)

add_public_tablegen_target(RISCVXVEC2CommonTableGen)

add_llvm_target(RISCVXVEC2CodeGen
  RISCVXVEC2TargetMachine.cpp
  )

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
