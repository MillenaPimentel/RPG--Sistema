int selec;
typedef struct{
    char nome[50];
    int nivel;
    int dado;
    int iniciativa;
}Personagem;

int rolagem(int dado){
    return rand() % (dado + 1);
}
Personagem lista[50];
int quant;
int adicionarPersongem(){
    if(quant >= 50){
        printf(" voce ja atingiu o maximo de personagens\n ");
}
    else{
Personagem p;
printf("\n insira o nome: ");
scanf("%d", &p.nome);
printf("\n insira o nivel: ");
scanf("%d", &p.nivel);
printf("\n insira o dado: ");
scanf("%d", &p.dado);

printf("\n personagem adicionado com sucesso!\n");
printf(" nome: %c\n", p.nome);
printf(" int: %d\n", p.nivel);
printf(" dado: %d\n", p.dado);
     quant++;
    }
}

int removerPersonagem(){
    
}
