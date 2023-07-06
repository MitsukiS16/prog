
# AC

---

# 01-RISC-V

## Sub-rotinas

### Conceito

![image](https://github.com/MitsukiS16/prog/assets/95706084/d22fd9a4-9290-4c05-a817-2cc5c0dadf44)


- O registo ****ra**** é usado para guardar o endereço de retorno

### Processo de invocação de uma sub-rotina: visão geral

1. Colocar argumentos nos registos `a0` até `a7`
    - A colocação de valores nos registos é feita por ordem (1º argumento em `a0`, 2º argumento em `a1`...)
2. Transferir o controlo de execução para a sub-rotina
    - Instrução primitiva usada é `jal`(*jump and link*)

<aside>
💡 jal → instrução utilizada para chamar funções.

- Salva o endereço de retorno (o endereço da próxima instrução) no registo `$ra`, antes de “saltar” para a função
- É a única instrução que pode aceder ao valor do PC (program counter), portanto pode armazenar o endereço de retorno PC+4 em `$ra`

</aside>


Fonte

1. Alocar memória para armazenar a informação local
    - Em particular, alocar espaço para variáveis locais
2. Executar o código da sub-rotina: seguir as regras de utilização de registos
3. Colocar o resultado no registo `a0`
4. Transferir controlo de volta para o local de chamada
    - A instrução primitiva usada é `jalr`

<aside>
💡 jalr (*jump and linke register*) → união entre `jal` e `jr` 
- Transfere controlo para o endereço num registo específico e armazena o endereço de registo no *************register file*************
- Permite ao programador especificar o registo de destino do endereço de retorno

</aside>


Fonte

### Utilização de registos em sub-rotinas

![image](https://github.com/MitsukiS16/prog/assets/95706084/dae0cb43-5376-49b4-bcb8-b9fc9600d5af)


Nota: não usar `x3` e `x4` (reservados para outras funções)

### Utilização de memória em sub-rotinas
![image](https://github.com/MitsukiS16/prog/assets/95706084/1c956859-0dbb-417e-9aac-ea9cd15f7b50)

******************************************Regras de utilização:******************************************

- Uma sub-rotina pode usar a zona livre da pilha
- Deve deixar a pilha como estava à entrada

### Regras para passagem de argumentos

Escalares

- Objetos com um único elemento (como números inteiros)
- Comprimento ≤ 32 bits são passados num registo
- 32 < comprimento ≤ 64 são passados em 2 registos consecutivos com a parte mais significativa no segundo registo

Agregados

- Objetos com mais de um elemento (como vetores)
- Seguem as mesmas regras de ≤ 32 (ou ≤ 64 para 2 registos)
- Quando não existem registos livres, os argumentos são passados na pilha
- Comprimento > 64 são passados por referência
    - Em vez do valor, é passado um ponteiro para o valor (o seu endereço)
- Os valores colocados na pilha obedecem a regras de alinhamento

### Regras para uso da pilha

- A pilha cresce para baixo, ou seja, na direção de endereços menores
- O ponteiro para a pilha (`sp`) deve ter um endereço múltiplo de 16 que deve estar sempre alinhado.
- O primeiro valor a ser passado na pilha fica na posição indicada por `sp`, sendo que os argumentos seguintes ficam em endereços superiores
![image](https://github.com/MitsukiS16/prog/assets/95706084/5e2e3fdb-c70a-4d92-9e3c-d3f465bf0982)


### Regras de alinhamento
![image](https://github.com/MitsukiS16/prog/assets/95706084/0675ee2d-b148-4dfc-bd66-352078d3c337)

Alinhamento da pilha: endereço de “topo” da pilha é um múltiplo de 16

### Instruções de invocação e retorno

- Invocar uma sub-rotina: “*jump and link*”

```nasm
jal x1, ProcedureLabel
```

- Endereço de retorno é colocado em `x1`
    - Salta para o endereço do início da sub-rotina
    - `call ProcedureLabel` é equivalente a `jal x1, ProcedureLabel`
    
- Retornar de uma sub-rotina: “************************jump and link register”************************

```nasm
jalr x0, x1, 0
```

- É um caso particular da instrução: `jalr reg1, reg2, imm`
    - Coloca endereço de retorno no registo `reg1`
    - Salta para a instrução na posição `reg2+imm`
    - `jal x0, x1, 0` é equivalente a `ret`

### Sub-rotina terminal (folha)

- Uma sub-rotina terminal (ou folha) não invoca outra sub-rotina

![image](https://github.com/MitsukiS16/prog/assets/95706084/c5a1dc22-9d93-4b02-8ce7-c9a4ff3a609e)


### Quem deve preservar registos?

A preservação de registos é feita na pilha.

- `ra (x1)` ⇒ usado tipicamente para guardar o endereço de retorno
    - Preservado pela sub-rotina “chamadora” (********caller********), significando que *caller* deve guarda-lo antes de chamar uma sub-rotina
- `t0-t6` ⇒ registos temporários
    - Preservados pela ***caller*** antes de chamar uma sub-rotina caso os seus valores sejam importantes após essa chamada (sub-rotina chamada pose usá-los sem restrições)
- `a0-a7` ⇒ argumentos de sub-rotinas e retorno de resultado
    - Preservados pela ***caller*** à semelhança dos registos temporários
- `s0-s11` ⇒ registos seguros
    - Preservados pela sub-rotina “chamada” (***callee***) ****, significando que antes de usar estes registos deve preservar os seus valores e recuperá-los antes de retornar à ***caller***.

## Exemplos

### Exemplo 1: uso de registos a preservar pela sub-rotina chamada (*callee)*
![image](https://github.com/MitsukiS16/prog/assets/95706084/382c7ec5-90a6-4418-8bb6-41d72e4e6749)

### Exemplo 2: uso de registos a reservar pela sub-rotina chamadora (*caller)*
![image](https://github.com/MitsukiS16/prog/assets/95706084/bf45d6d3-8e3a-4504-a083-7abf0d67007e)


### Uma sub-rotina com variáveis locais
![image](https://github.com/MitsukiS16/prog/assets/95706084/01c2ffe1-23fb-44e8-a0f8-0a59ad1fc502)

### Invocação encadeada de sub-rotinas

![image](https://github.com/MitsukiS16/prog/assets/95706084/548ebfc3-e077-47f3-a9e6-4334364d05fe)


## Vírgula flutuante

### Suporte para operações de vírgula flutuante (VF)

Existência de 32 registos adicionais de vírgula flutuante: `f0-f31`, sendo que cada tem 64 bits, e pode ter um valor de precisão dupla ou de precisão simples:

- um valor de precisão simples ocupa os bits menos significativos do registo
- os bits mais significativos (não usado em precisão simples) estão a 1

Categorias de instruções:

- acesso à memória
- cálculo
- conversão e transferência
- comparação
- classificação

### VF: acesso à memória

- Precisão dupla
    - load
    
    ```nasm
    fld freg, imm(ireg)  ->  fld f1, 100(t1)
    ```
    
    - store
    
    ```nasm
    fsd freg, imm(ireg) -> fsd f1, 100(t2)
    ```
    

- Precisão simples
    - load
    
    ```nasm
    flw freg, imm(ireg) -> flw f1, 100(t1)
    ```
    
    - store
    
    ```nasm
    fsw freg, imm(ireg) -> fsw f1, 100(t2)
    ```
    

### VF: Operações de cálculo

- `FADD`/`FSUB` ⇒ adição e subtração
- `FMUL`/`FDIV` ⇒ multiplicação e divisão
- `FSQRT` ⇒ raiz quadrada
- `FMIN`/`FMAX` ⇒ mínimo, máximo
- `FABS`, `FNEG` ⇒ valor absoluto, simétrico (trocar o sinal)
- **Precisão simples**: sufixo “.s”
    
    ```nasm
    fmax.s f1, f2, f3 -> f1 = max(f2,f3)
    ```
    
- Precisão **dupla**: sufixo “.d”
- Multiplicação e adição (”fused add-multiply”) numa **única instrução**

```nasm
FMADD.{S,D}  f1,f2,f3,f4 -> f1 = f2 * f3 + f4
FMSUB.{S,D}  f1,f2,f3,f4 -> f1 = f2 * f3 - f4
FNMADD.{S,D} f1,f2,f3,f4 -> f1 = -(f2 * f3 + f4)
FNMSUB,{S,D} f1,f2,f3,f4 -> f1 = -(f2*f3-f4)
```

### VF: Conversão entre formatos

O tipo de registo deve corresponder ao tipo de dados.

- Formato: `FCVT**.destfmt.srcfmt** regdest, regsource`
    - **inteiros**: **w** (word), **wu** (unsigned word)
    - **vírgula flutuante**: **s** (single), **d** (double)
        - Exemplos:
        
        ```nasm
        fcvt.w.s t1,f3   -> t1 = inteiro(f3) com arredondamento
        fcvt.s.w f4,t0   -> f4 = float(f4)
        fcvt.s.d f4,f5   -> f4 = float(f5) com arredondamento
        ```
        
- Transferência sem conversão (cópia de bits): apenas para precisão simples
    
    ```nasm
    fmv.x.s f1,t1   -> f1 = cópia dos bits de t1
    fmv.s.x t1,f1   -> t1 = cópia dos bits de t1
    ```
    

### Gamas de valores para conversões de precisão simples para inteiros
![image](https://github.com/MitsukiS16/prog/assets/95706084/7687911b-491a-4f2b-ba49-330c7bde39c0)


### VF: Operações de comparação

O resultado da comparação é 0 ou 1 e fica num registo de números inteiros.

- Igual

```nasm
FEQ.{S,D}   t1,f1,f2
```

- Menor

```nasm
FLT.{S,D}   t1,f1,f2
```

- Menor ou igual

```nasm
FLE.{S,D}   t1,f1,f2
```

Classificação de números VF: 

```nasm
FCLASS.{S,D}   t1,rs1
```

- O registo t1 fica com um código de classificação do valor de `rs1`

![image](https://github.com/MitsukiS16/prog/assets/95706084/60143a33-74d0-4d95-9bef-828f8f8f1991)


### Gestão de registos VF em sub-rotinas

- Argumentos de VF são passados nos registos `fa0-fa7` (`f10-f17`)
    - O registo `fa0` é usado para desenvolver **resultado se este for de VF**
    - Argumentos em VF são passados nestes registos sempre que possível
- Os registos `fs0-fs11` devem ser **preservados** pelas sub-rotinas
- Os registos `ft0-ft11` podem ser **usados** pelas sub-rotinas

**Nota:** O registo `f0` não é especial.

---

# Pipeline

### Exercicio 1 - Ficha 4

1. Na etapa de **busca de instrução (IF)** do pipeline de processamento, o processador busca a próxima instrução na memória de instruções e a carrega no registrador de instrução. Nesse estágio, não ocorre nenhuma operação que seja específica para a instrução SW, uma vez que ainda não se sabe qual é a instrução a ser executada.
Porém, mesmo em uma instrução SW, todos os componentes da etapa IF são importantes, uma vez que é necessário buscar a próxima instrução a ser executada. Isso inclui o endereço da próxima instrução, que é necessário para buscar a instrução na memória de instruções. Além disso, durante a busca de instrução, podem ocorrer problemas como falhas de cache ou de predição de salto, que precisam ser tratados.
Portanto, embora a instrução SW não envolva diretamente a etapa IF do pipeline, essa etapa continua sendo importante para o processamento da instrução e deve ser considerada em todo o processo de execução.
2. Na etapa de **descodificação de instrução (ID)** do pipeline de processamento, a instrução previamente carregada no registrador de instrução na etapa IF é decodificada para determinar qual operação deve ser executada e quais registradores ou memória serão utilizados.
Na instrução SW, durante a etapa ID, o processador identifica que o registrador $t contém o valor que deve ser armazenado na memória e que o registrador $s contém o endereço base da memória. Além disso, o valor do offset é adicionado ao endereço base para determinar o endereço de memória onde o valor deve ser armazenado.
Todos esses componentes são úteis na etapa ID para a execução da instrução SW, pois é necessário determinar quais registradores e endereços de memória serão utilizados para armazenar o valor. Além disso, durante a etapa ID, é possível detectar possíveis problemas de dependência de dados ou conflitos de registradores que possam ocorrer durante a execução da instrução SW.
Portanto, todos os componentes da etapa ID são importantes para a execução da instrução SW e devem ser considerados durante todo o processo de execução do pipeline
3. Na etapa de **execução (EX)** do pipeline de processamento, a instrução é efetivamente executada. Na instrução SW, a etapa EX envolve o cálculo do endereço de memória onde o valor será armazenado.
Durante a execução da instrução SW, o componente da ALU que realiza a operação de soma (Add) é utilizado para calcular o endereço de memória final onde o valor será armazenado. Portanto, o componente de soma da ALU é considerado útil na etapa EX da instrução SW.
No entanto, a saída Zero da ALU, que indica se o resultado da operação da ALU é zero ou não, não é considerada útil na instrução SW, uma vez que não há necessidade de verificar se o resultado é zero ou não para a execução da instrução.
Além disso, outros componentes na etapa EX, como registradores temporários e multiplexadores, são importantes para a execução da instrução SW, pois ajudam a gerenciar os dados e garantir que o valor correto seja armazenado na memória.
Portanto, embora o componente de saída Zero da ALU não seja considerado útil na instrução SW, outros componentes na etapa EX são importantes e devem ser considerados durante todo o processo de execução do pipeline.
4. Na etapa de **acesso à memória (MEM)** do pipeline de processamento, a instrução SW armazena um valor em uma determinada posição de memória. Durante esta etapa, o endereço de memória é calculado na etapa anterior (EX) e o valor é armazenado na memória de dados.
Na instrução SW, o componente do porto de leitura da memória não produz resultados úteis, pois não há necessidade de ler um valor da memória. No entanto, os demais componentes na etapa MEM são importantes e produzem resultados úteis. O componente do porto de escrita da memória é utilizado para escrever o valor calculado na etapa EX na memória de dados. Além disso, o registrador de saída da etapa MEM contém o valor que foi armazenado na memória.
É importante destacar que, embora o componente do porto de leitura da memória não seja utilizado na instrução SW, ele pode ser útil em outras instruções que envolvam a leitura de dados da memória.
Portanto, na instrução SW, o componente do porto de leitura da memória não produz resultados úteis, mas os demais componentes na etapa MEM são importantes e devem ser considerados durante todo o processo de execução do pipeline.
5. Na etapa de **escrita de volta (WB)** do pipeline de processamento, os resultados da instrução são escritos nos registradores do processador. Na instrução SW, não há valores retornados ou escritos nos registradores do processador, já que o valor a ser armazenado é diretamente escrito na memória de dados.
Portanto, na instrução SW, a etapa WB não produz resultados úteis, uma vez que não há valores a serem escritos nos registradores do processador. Os resultados úteis da instrução SW são armazenados diretamente na memória de dados e não requerem a escrita de qualquer valor nos registradores do processador.
No entanto, em outras instruções que envolvam operações aritméticas ou lógicas, a etapa WB é importante para a escrita dos resultados dessas operações nos registradores do processador, que podem ser usados por instruções subsequentes no pipeline.
Em resumo, na instrução SW, a etapa WB não produz resultados úteis, mas em outras instruções, a etapa WB é importante para a escrita dos resultados nos registradores do processador.

Identique todas as dependências de dados da sequência de código apresentada a seguir. Indique
que conitos podem ser resolvidos por atalhos e quais provocam protelamentos.
add s3 , s4 , s2
sub s5 , s3 , s1
lw s6 , 200( s3)
add s7 , s3 , s6

---

---

# Cache

## Definições

### Indice (posição)

Endereço de memória % nº blocos (% - resto da divisão)

- Se o nº de blocos = 2^b, o índice é dado pelos **b** bits menos significativos do endereço

### Etiqueta (tag)

- Constituída pelos bits mais significativos do endereço
- Cada bloco tem associado um  bit de validade
- Se bit=0, bloco é inválido (posição da cache está vazia)

### Número de blocos

2^nº indice

### Número de bytes por bloco

2^(bitsTotal-bitsTag-bitsIndice)
