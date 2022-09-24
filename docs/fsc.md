FSC


Representação de Números
Circuitos
Sistemas de Memória
Assembly
CPU







CPU

Tipo de Instruções:
> Instruções lógico-aritméticas -> R (and, sub, and, orr)
> Instruções de acesso a memória -> ldur, stur
> instruções de salto -> B, CBZ

Codificação das Instruções:
> Tipo R -> opcode [11bits]  + Rm [5 bits] + shamt [6bits] + Rn [5bits] +  Rd [5 bits]
> Tipo D -> opcode [11bits]  + offset [9 bits] + op2 [2bits] + Rn [5bits] +  Rd [5 bits]
> Tipo CB  -> opcode [8bits] + address [19bits] + Rt [5 bits]
> Tipo B -> opcode [6 bits] + address [26 bits] 

Unidade de Cálculo: Para realizar cálculos, o processador inclui:
> circuito combinatório que pode realizar uma de várias operações
> duas entradas de dados de N bits e uma entrada de controlo de C bits
> uma saída de n bits para o resultado e uma saída de 1 bit indicando se o resultado é 0

Sinais de controlo de ALU		Função			Operação
0000					AND				R = A & B
0001					OR				R = A | B
0010					adição 				R = A + B
0110					subtração			R = A - B
0111					transferir entrada B		R = B
1100					NOT				R = (A ou B) [sublinhado]

Ações de Instruções:
> 1º Passo: Enviar o conteúdo do contador de programa para a memória de instruções e obter a instrução;
> 2º Passo: Ler um ou dois registos. A instrução LDUR apenas necessita de ler um registo (2º registo é lindo mas “ignorado”).

Instruções ALU:
> Lógico-aritméticas: ALU efetua a operação;
> Load/Store: ALU é usada para cálculo do endereço efetivo;
> Salto condicional: ALU é usada para efetuar a comparação.

Componentes para acesso a memória de dados:
> MemRead
> MemWrite
Componentes para avaliação da condição de salto:
> ALU 

MemRead:
> Sinal de habilitação de leitura
> Necessário para evitar a leitura de endereços ilegais (surgem na entrada address durante a execução de outras instruções que não acedem à memória).

MemWrite:
> SInal de habilitação de escrita

Ctrl ALU
> Objetivo: separar a unidade de controlo em duas;
> Trabalha em: instruções lógico aritméticas; cálculo de endereços e comparação.

Sinais de Controlo:
		Se valor = 0					Se valor = 1
Reg2Loc	Nº Registos 2 vem do Rm			Nº Registos 2 vem do Rt
RegWrite 	- 						Registo campo 4:0 recebe valor WriteData
ALUSrc	2º Op ALU vem saída 2			2ª Op ALU é constante da Instrução
PCSrc		PC assume valor PC+4			PC <- destino do salto
MemRead	-						Memória fornece valor perdido
MemWrite	-						Memória guarda valor da entrada WriteData
MemtoReg	Valor banco de registos provém ALU		Valor banco de registos provém da memória
Branch 	Instrução não é CBZ				Instrução é CBZ

Especificação do controlador principal:

Instrução
Reg2Loc
ALUSrc
MemtoReg
RegWrite
MemRead
MemWrite
Branch
ALUop[1]
ALUop[0]
R
0
0
0
1
0
0
0
1
0
LDUR
x
1
1
1
1
0
0
0
0
STUR
1
1
x
0
0
1
0
0
0
CBZ
1
0
x
0
0
0
1
0
1








Quiz CPU (Moodle)

Processamento da instrução and x0, x0, x7
AND -> Tipo R 
Tipo R -> RegWrite e ALUop[1] = 1; resto = 0
Instrução
Reg2Loc
ALUSrc
MemtoReg
RegWrite
MemRead
MemWrite
Branch
ALUop[1]
ALUop[0]
R
0
0
0
1
0
0
0
1
0

R: MemRead = 0 e ALUrc = 0

Processamento da instrução cbz
Tipo cbz -> Reg2Loc = 1, Branch = 1; ALUop[1] = 1, MemtoReg = x; resto = 0
Instrução
Reg2Loc
ALUSrc
MemtoReg
RegWrite
MemRead
MemWrite
Branch
ALUop[1]
ALUop[0]
CBZ
1
0
x
0
0
0
1
0
1

R: ALUSrc = 0

Processamento da instrução sub xo, x1, x2:
Sub -> Tipo R
Tipo R -> RegWrite = 1, ALUop[1] = 1; resto = 0
R: Reg2Loc = 0 e MemtoReg = 0

Processamento da instrução stur:
Tipo stur -> Reg2Loc = 1, ALUSrc = 1, MemWrite = 1; MemtoReg = x; resto = 0
Instrução
Reg2Loc
ALUSrc
MemtoReg
RegWrite
MemRead
MemWrite
Branch
ALUop[1]
ALUop[0]
STUR
1
1
x
0
0
1
0
0
0

R: Reg2Loc = 1

Se ALUSrc = 1
Existem 4 Tipos de Instruções:
> R -> ALUSrc = 0
> LDUR -> ALUSrc = 1
> SDUR -> ALUSrc = 1
> CBZ -> ALUSrc = 0
R: As instruções R, add e CBZ deixam de funcionar.

Se Reg2Loc = 1
R: As instruções add, sub, LDUR deixam de funcionar.

Instrução add
add -> Tipo R
Instrução
Reg2Loc
ALUSrc
MemtoReg
RegWrite
MemRead
MemWrite
Branch
ALUop[1]
ALUop[1]
R
0
0
0
1
0
0
0
1
0

		Se valor = 0					Se valor = 1
Reg2Loc	Nº Registos 2 vem do Rm			Nº Registos 2 vem do Rt
RegWrite 	- 						Registo campo 4:0 recebe valor WriteData
ALUSrc	2º Op ALU vem saída 2			2ª Op ALU é constante da Instrução
PCSrc		PC assume valor PC+4			PC <- destino do salto
MemRead	-						Memória fornece valor perdido
MemWrite	-						Memória guarda valor da entrada WriteData
MemtoReg	Valor banco de registos provém ALU		Valor banco de registos provém da memória
Branch 	Instrução não é CBZ				Instrução é CBZ




Instrução STUR
PC -> relacionado com PCSrc -> PCSrc = 1 -> PC não assume PC+4;
Banco de Registos -> 






[--FIM–]
