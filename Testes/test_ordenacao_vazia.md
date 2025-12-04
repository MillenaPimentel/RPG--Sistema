# Teste: ordenação com lista vazia (`test_ordenacao_vazia.c`)

## Objetivo

Verificar se a função `ordenar` trata corretamente o caso em que a quantidade de personagens (`qtd`) é zero, sem acessar posições inválidas do vetor e sem travar o programa.

## Cenário do teste

- Vetor `Personagem lista[1];` (tamanho mínimo apenas para existir).
- Variável `int qtd = 0;` indicando que não há nenhum personagem na lista.
- Chamada da função:

ordenar(lista, qtd, 1); // 1 = Quick Sort


## Comportamento esperado

Como `qtd <= 1`, a função `ordenar` retorna imediatamente, sem tentar acessar índices do vetor.  
Ao final, o teste imprime:

TESTE ORDENACAO (LISTA VAZIA): OK


## Como compilar e executar

Na pasta raiz do projeto:

gcc Testes/test_ordenacao_vazia.c rpg.c -o Testes/test_ordenacao_vazia.exe
Testes\test_ordenacao_vazia.exe

