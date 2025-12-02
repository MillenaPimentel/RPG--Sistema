#include "ponto.h"


int quantPersonagens = 0;
Personagem lista[50];

int mostrarPersonagens(){
    for(int i = 0; i < quantPersonagens; i++){
        printf("ID %d - %c\n", i, lista[i].nome);
    }
}

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

int removerPersonagem(void){
    if (quantPersonagens < 1){
        printf("voce nao possui personagens.\n");
    }
    else{
        int ID = 0;
        printf("selecione qual personagem deseja excluir: \n");
        int mostrarPersonagens();
        scanf("%d", &ID);
        if(ID < 0 || ID > quantPersonagens - 1){
            printf("esse ID eh invalido\n");
            return 0;
        }
            for(int i = ID; i < quantPersonagens - 1; i++){
                lista[i] = lista[i + 1];
            }
            quantPersonagens--;
            printf("personagem removido com sucesso\n");
    }
}

int rolagem(int dado){
    return rand() % (dado + 1);
}
