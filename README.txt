// =========================================================
// PROJETO PILOTO (RISCVXVEC2)
// =========================================================

01) - COMPILAR COM O CLANG

 	~/riscvxvec2/build/bin/./clang -c -emit-llvm ~/riscvxvec2/build/testes/teste_llvm.c -o ~/riscvxvec2/build/testes/teste_llvm.ir

	1.1) - Exibir o IR criado

 		~/riscvxvec2/build/bin/./opt --view-cfg ~/riscvxvec2/build/testes/teste_llvm.ir

02) - REALIZAR OTIMIZAÇÕES PERSONALIZADAS

	opt [options] [filename]

03) - SUGESTÃO PARA PARSE DE VETORIZAÇÃOO (SLP VECTORIZER)

	3.1) - Processo para criar a IR
		$ clang ... -fno-vectorize  file.c

	3.2) - otimizações na anteriores a IR e Posteriores opt
		$ clang  -mllvm -force-vector-width=8 ...
		$ opt -loop-vectorize -force-vector-width=8 ...

		$ clang  -mllvm -force-vector-interleave=2 ...
		$ opt -loop-vectorize -force-vector-interleave=2 ...


04) - LISTAR AS ARQUITETURAS INSTALADAS

		~/riscvxvec2/build/bin/./llc --version

05) - COMPILAR PARA A ARQUITETURA ESCOLHIDA

		~/riscvxvec2/build/bin/./llc --march=riscvxvec32 ~/riscvxvec2/build/testes/teste_llvm.ir

// =========================================================
// PROJETO ALTERNATIVO (RISCVXVEC) - IMPRESSORA MSP430
// =========================================================

Mesmos comandos contudo substituir riscvxvec2 por riscvxvec

04) - LISTAR AS ARQUITETURAS INSTALADAS

		~/riscvxvec/build/bin/./llc --version

05) - COMPILAR PARA A ARQUITETURA ESCOLHIDA

~/riscvxvec/build/bin/./llc --march=riscvxvec2 ~/riscvxvec/build/testes/teste_llvm.ir