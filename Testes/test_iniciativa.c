#include <stdio.h>
#include <string.h>
#include "../rpg.h"

// Versão do teste: não usa rand, usa valor fixo de dado
void calcularIniciativa_teste(Personagem *lista, int qtd, int valorDado) {
    for (int i = 0; i < qtd; i++) {
        lista[i].iniciativa = lista[i].nivel + valorDado;
    }
}

void testar_iniciativa_simples() {
    Personagem p;
    strcpy(p.nome, "Heroi");
    p.nivel = 5;
    p.dado = 6;
    p.iniciativa = 0;

    calcularIniciativa_teste(&p, 1, 3); // dado = 3

    if (p.iniciativa == 8) {
        printf("TESTE INICIATIVA SIMPLES: OK\n");
    } else {
        printf("TESTE INICIATIVA SIMPLES: FALHOU (esperado 8, obtido %d)\n", p.iniciativa);
    }
}

int main() {
    testar_iniciativa_simples();
    return 0;
}
