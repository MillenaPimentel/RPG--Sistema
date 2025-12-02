#include <stdio.h>
#include "ponto.h"

int selec = 0;

while (selec != 5){

scanf("%d", &selec);

printf("\nBem vindo jogador.\n\n");
printf("1 - Ver meus personagens.\n");
printf("2 - Adicionar Personagem.\n");
printf("3 - Remover Personagem.\n");
printf("4 - Iniciar Combate.\n");
printf("5 - Finalizar.\n");



    switch (selec){
        case 1:
            mostrarPersonagens();
            break;
        case 2:
            adicionarPersonagem();
        break;
        case 3:
            removerPersonagem();
        break;
        case 4:
            iniciarCombate();
        break;
        case 5:
            //sair do trem
        break;
    }
}
