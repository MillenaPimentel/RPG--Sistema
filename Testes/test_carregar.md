# Teste: carregarArquivo (`test_carregar.c`)

## Objetivo

Garantir que a função `carregarArquivo` lê corretamente vários personagens do arquivo `personagens.txt` e atualiza a quantidade `qtd` e a lista em memória.

## Arquivo de entrada

**Arquivo usado:** `personagens.txt`

Gandalf;10;12;0
Aragorn;8;8;0
Legolas;5;6;0


Formato de cada linha:

- `nome;nivel;dado;iniciativa`

## Passos do teste

1. Criar o vetor `Personagem lista[MAX_PERSONAGENS];`.
2. Inicializar `int qtd = 0;`.
3. Chamar `carregarArquivo(&qtd, lista);`.
4. Verificar:
   - se `qtd == 3`;
   - se `lista[0].nome == "Gandalf"`;
   - se `lista[1].nome == "Aragorn"`;
   - se `lista[2].nome == "Legolas"`.
5. Imprimir no console:
   - `TESTE CARREGAR: OK (qtd=3)` se todas as verificações forem verdadeiras;
   - `TESTE CARREGAR: FALHOU (qtd=X)` caso contrário.

## Como compilar e executar

Na pasta raiz do projeto:

Testes\test_carregar.exe


## Resultado esperado

Saída no terminal:

TESTE CARREGAR: OK (qtd=3)


Isso mostra que o sistema está conseguindo carregar corretamente 3 personagens do arquivo `personagens.txt`.
