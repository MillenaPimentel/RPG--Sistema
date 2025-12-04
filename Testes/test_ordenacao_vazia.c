#include <stdio.h>
#include "../rpg.h"

// Teste de ordenação com lista vazia
void testar_ordenacao_lista_vazia() {
    Personagem lista[1];
    int qtd = 0;

    ordenar(lista, qtd, 1);  // 1 = Quick Sort

    printf("TESTE ORDENACAO (LISTA VAZIA): OK\n");
}

int main() {
    testar_ordenacao_lista_vazia();
    return 0;
}
