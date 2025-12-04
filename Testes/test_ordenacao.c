#include <stdio.h>
#include <string.h>
#include "rpg.h"

// Função auxiliar para imprimir resultado do teste
void testar_ordenacao() {
    Personagem lista[3];

    strcpy(lista[0].nome, "A");
    lista[0].nivel = 1;
    lista[0].dado = 20;
    lista[0].iniciativa = 5;

    strcpy(lista[1].nome, "B");
    lista[1].nivel = 1;
    lista[1].dado = 20;
    lista[1].iniciativa = 15;

    strcpy(lista[2].nome, "C");
    lista[2].nivel = 1;
    lista[2].dado = 20;
    lista[2].iniciativa = 10;

    // 2 = Insertion Sort 
    ordenar(lista, 3, 2);

    if (lista[0].iniciativa == 15 &&
        lista[1].iniciativa == 10 &&
        lista[2].iniciativa == 5) {
        printf("TESTE ORDENACAO: OK\n");
    } else {
        printf("TESTE ORDENACAO: FALHOU\n");
    }
}


void testar_ordenacao_lista_ja_ordenada() {
    Personagem lista[3];

    strcpy(lista[0].nome, "X");
    lista[0].nivel = 1;
    lista[0].dado = 20;
    lista[0].iniciativa = 20;

    strcpy(lista[1].nome, "Y");
    lista[1].nivel = 1;
    lista[1].dado = 20;
    lista[1].iniciativa = 10;

    strcpy(lista[2].nome, "Z");
    lista[2].nivel = 1;
    lista[2].dado = 20;
    lista[2].iniciativa = 1;

    ordenar(lista, 3, 2); // Insertion Sort

    if (lista[0].iniciativa == 20 &&
        lista[1].iniciativa == 10 &&
        lista[2].iniciativa == 1) {
        printf("TESTE ORDENACAO (JA ORDENADA): OK\n");
    } else {
        printf("TESTE ORDENACAO (JA ORDENADA): FALHOU\n");
    }
}
int main() {
    testar_ordenacao();
    testar_ordenacao_lista_ja_ordenada();
    return 0;
}
