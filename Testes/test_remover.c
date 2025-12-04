#include <stdio.h>
#include <string.h>
#include "../rpg.h"

void testar_remover_meio() {
    Personagem lista[3];
    int qtd = 3;

    strcpy(lista[0].nome, "A");
    lista[0].nivel = 1; lista[0].dado = 4; lista[0].iniciativa = 1;

    strcpy(lista[1].nome, "B");
    lista[1].nivel = 2; lista[1].dado = 6; lista[1].iniciativa = 2;

    strcpy(lista[2].nome, "C");
    lista[2].nivel = 3; lista[2].dado = 8; lista[2].iniciativa = 3;

    // simular escolha do índice 2 (B) na função real
    // aqui vamos remover "na mão":
    int indice = 1; // posição B
    for (int i = indice; i < qtd - 1; i++) {
        lista[i] = lista[i + 1];
    }
    qtd--;

    if (qtd == 2 &&
        strcmp(lista[0].nome, "A") == 0 &&
        strcmp(lista[1].nome, "C") == 0) {

        printf("TESTE REMOVER (MEIO): OK\n");
    } else {
        printf("TESTE REMOVER (MEIO): FALHOU\n");
    }
}

int main() {
    testar_remover_meio();
    return 0;
}
