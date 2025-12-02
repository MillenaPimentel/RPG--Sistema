#include "ponto.h"


int quantPersonagens = 0;
personagem lista[50];

int adicionarPersongem(void){
    if(quantPersonagens >= 50){
        printf(" voce ja atingiu o maximo de personagens\n ");
}
    else{
    Personagem *p = &lista[quantPersonagens];
    printf("\n insira o nome: ");
    scanf("%c", &p.nome);
    printf("\n insira o nivel: ");
    scanf("%d", &p.nivel);
    printf("\n insira o dado: ");
    scanf("%d", &p.dado);
    p->iniciativa = rolagem(p->dado);
    printf("\n personagem adicionado com sucesso!\n");
    printf("esse é o ID do seu personagem: %d \n", quantPersonagens);
    printf(" nome: %c\n", p->nome);
    printf(" int: %d\n", p->nivel);
    printf(" dado: %d\n", p->dado);
     quantPersonagens++;
    }
    
}

int rolagem(int dado){
    return rand() % (dado + 1);
}
