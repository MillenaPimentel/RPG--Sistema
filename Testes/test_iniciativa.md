# Testes de Iniciativa

**Arquivo de testes:** `Testes/test_iniciativa.c`  
**Função testada:** `calcularIniciativa()`  
**Lógica verificada:** cálculo da iniciativa (`nível + valor do dado`)

## Caso de Teste 1 – Iniciativa Simples

### Objetivo
Verificar se a iniciativa é calculada corretamente como `nível + dado`.

### Implementação do Teste
- Criada função auxiliar `calcularIniciativa_teste()` que substitui `rand()` por valor fixo de dado.

### Dados de Entrada
| Campo | Valor |
|-------|-------|
| Nome | "Heroi" |
| Nível | 5 |
| Dado | 6 (d6) |
| Iniciativa inicial | 0 |
| **Valor do dado no teste** | **3 (fixo)** |

### Resultado Esperado

TESTE INICIATIVA SIMPLES: OK

**Cálculo:** `5 + 3 = 8`

### Critério de Sucesso
- Campo `iniciativa` do personagem deve ser atualizado para **8**.

## Como Executar

Na pasta raiz do projeto:

gcc Testes/test_iniciativa.c rpg.c -o Testes/test_iniciativa.exe
Testes\test_iniciativa.exe

