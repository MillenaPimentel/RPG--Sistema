#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "rpg.h"

int main() {
    Personagem personagens[MAX_PERSONAGENS];
    int qtdPersonagens = 0;
    int metodoOrdenacao = 1; // 1 = Quick Sort, 2 = Insertion Sort

    srand(time(NULL)); // semente do rand

    int opcao;
    do {
        opcao = menuPrincipal();

        switch (opcao) {
            case 1:
                criarPersonagem(personagens, &qtdPersonagens);
                break;
            case 2:
                listarPersonagens(personagens, qtdPersonagens);
                break;
            case 3:
                removerPersonagem(personagens, &qtdPersonagens);
                break;
            case 4:
                selecionarMetodoOrdenacao(&metodoOrdenacao);
                break;
            case 5:
                loopCombate(personagens, &qtdPersonagens, &metodoOrdenacao);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

