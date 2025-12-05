# Testes do sistema de RPG

Este arquivo descreve os testes automatizados criados para o projeto.

## Testes de ordenação da iniciativa

Arquivo de testes: `test_ordenacao.c`  
Função testada: `ordenar(Personagem *lista, int qtd, int metodoOrdenacao)`

### Caso de teste 1 – Lista desordenada

- Objetivo: verificar se a função `ordenar` organiza os personagens em ordem **decrescente** de iniciativa.
- Entrada:
  - 3 personagens com iniciativas: `5`, `15`, `10`
- Passos:
  1. Compilar:
     ```
     gcc test_ordenacao.c rpg.c -o test_ordenacao.exe
     ```
  2. Executar:
     ```
     test_ordenacao.exe
     ```
- Resultado esperado na tela:
   TESTE ORDENACAO: OK

   - Critério de sucesso:
- Após a ordenação, a ordem das iniciativas deve ser: `15`, `10`, `5`.

### Caso de teste 2 – Lista já ordenada

- Objetivo: garantir que a função `ordenar` não “quebre” uma lista que já está em ordem correta.
- Entrada:
- 3 personagens com iniciativas: `20`, `10`, `1`
- Passos:
1. Compilar:
   ```
   gcc test_ordenacao.c rpg.c -o test_ordenacao.exe
   ```
2. Executar:
   ```
   test_ordenacao.exe
   ```
- Resultado esperado na tela:
   TESTE ORDENACAO (JA ORDENADA): OK

- Critério de sucesso:
- Após a ordenação, a ordem das iniciativas deve continuar: `20`, `10`, `1`.

## Como executar todos os testes

Na pasta do projeto:

gcc Testes/test_ordenacao.c rpg.c -o Testes/test_ordenacao.exe
Testes\test_ordenacao.exe


Se ambos os casos estiverem corretos, o programa exibirá:

   TESTE ORDENACAO: OK
   TESTE ORDENACAO (JA ORDENADA): OK

