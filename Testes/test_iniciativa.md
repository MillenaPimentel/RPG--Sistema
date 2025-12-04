# Testes de iniciativa

Arquivo de testes: `test_iniciativa.c`  
Função de lógica testada: cálculo da iniciativa (nível + valor do dado)

## Caso de teste 1 – Iniciativa simples

- Objetivo: verificar se a iniciativa é calculada corretamente como `nivel + dado`.
- Implementação:
  - Foi criada uma função de teste `calcularIniciativa_teste`, que recebe um valor fixo de dado (sem aleatoriedade).
- Entrada:
  - Personagem com:
    - nome: "Heroi"
    - nivel: 5
    - dado: d6
    - iniciativa inicial: 0
  - Valor do dado usado no teste: 3
- Passos para executar:
  1. Na pasta raiz do projeto, compilar:
     ```
     gcc Testes/test_iniciativa.c rpg.c -o test_iniciativa.exe
     ```
  2. Executar:
     ```
     test_iniciativa.exe
     ```
- Resultado esperado na tela:
# Testes de iniciativa

Arquivo de testes: `test_iniciativa.c`  
Função de lógica testada: cálculo da iniciativa (nível + valor do dado)

## Caso de teste 1 – Iniciativa simples

- Objetivo: verificar se a iniciativa é calculada corretamente como `nivel + dado`.
- Implementação:
  - Foi criada uma função de teste `calcularIniciativa_teste`, que recebe um valor fixo de dado (sem aleatoriedade).
- Entrada:
  - Personagem com:
    - nome: "Heroi"
    - nivel: 5
    - dado: d6
    - iniciativa inicial: 0
  - Valor do dado usado no teste: 3
- Passos para executar:
  1. Na pasta raiz do projeto, compilar:
     ```
     gcc Testes/test_iniciativa.c rpg.c -o test_iniciativa.exe
     ```
  2. Executar:
     ```
     test_iniciativa.exe
     ```
- Resultado esperad# Testes de iniciativa

Arquivo de testes: `test_iniciativa.c`  
Função de lógica testada: cálculo da iniciativa (nível + valor do dado)

## Caso de teste 1 – Iniciativa simples

- Objetivo: verificar se a iniciativa é calculada corretamente como `nivel + dado`.
- Implementação:
  - Foi criada uma função de teste `calcularIniciativa_teste`, que recebe um valor fixo de dado (sem aleatoriedade).
- Entrada:
  - Personagem com:
    - nome: "Heroi"
    - nivel: 5
    - dado: d6
    - iniciativa inicial: 0
  - Valor do dado usado no teste: 3
- Passos para executar:
  1. Na pasta raiz do projeto, compilar:
     ```
     gcc Testes/test_iniciativa.c rpg.c -o test_iniciativa.exe
     ```
  2. Executar:
     ```
     test_iniciativa.exe
     ```
- Resultado esperado na tela:
    TESTE INICIATIVA SIMPLES: OK

- Critério de sucesso:
- O campo `iniciativa` do personagem deve ser atualizado para `8` (`5 + 3`).

## Como executar os testes de iniciativa

Na pasta do projeto:

"gcc Testes/test_iniciativa.c rpg.c -o test_iniciativa.exe
test_iniciativa.exe"
