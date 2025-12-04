# Teste: remover personagem do meio (`test_remover.c`)

## Objetivo

Verificar se a lógica de remoção de personagem no vetor mantém a ordem correta dos elementos, removendo um personagem do meio e “puxando” os demais para a esquerda.

## Cenário do teste

Vetor inicial com 3 personagens:

1. `A` (posição 0)  
2. `B` (posição 1)  
3. `C` (posição 2)  

Remoção simulada do personagem `B` (índice 1).

## Passos do teste

1. Criar vetor `lista[3]` preenchido com `A`, `B`, `C`.
2. Definir `qtd = 3`.
3. Executar o laço de remoção:

for (int i = 1; i < qtd - 1; i++) {
lista[i] = lista[i + 1];
}
qtd--;


4. Verificar:
- se `qtd == 2`;
- se `lista[0].nome == "A"`;
- se `lista[1].nome == "C"`.

5. Imprimir:
- `TESTE REMOVER (MEIO): OK` se todas as condições forem verdadeiras;
- `TESTE REMOVER (MEIO): FALHOU` caso contrário.

## Como compilar e executar

gcc Testes/test_remover.c rpg.c -o Testes/test_remover.exe
Testes\test_remover.exe


## Resultado esperado

TESTE REMOVER (MEIO): OK


Isso mostra que a lógica de remoção preserva os personagens restantes na ordem correta depois de retirar um elemento do meio do vetor.

