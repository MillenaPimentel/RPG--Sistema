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
}

int removerPersonagem(){
}
