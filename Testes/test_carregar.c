#include <stdio.h>
#include <string.h>
#include "../rpg.h"

void testar_carregar() {
    Personagem lista[MAX_PERSONAGENS];
    int qtd = 0;

    carregarArquivo(&qtd, lista);

    if (qtd == 3 &&
        strcmp(lista[0].nome, "Gandalf") == 0 &&
        strcmp(lista[1].nome, "Aragorn") == 0 &&
        strcmp(lista[2].nome, "Legolas") == 0) {

        printf("TESTE CARREGAR: OK (qtd=%d)\n", qtd);
    } else {
        printf("TESTE CARREGAR: FALHOU (qtd=%d)\n", qtd);
    }
}

int main() {
    testar_carregar();
    return 0;
}
