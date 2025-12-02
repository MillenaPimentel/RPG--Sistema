int selec;
typedef struct{
    char nome[50];
    int nivel;
    int dado;
    int iniciativa;
}Personagem;

int rolagem(int dado);
int contagemTurno;
int adicionarPersongem(void);
int removerPersonagem(void);
int editarPersonagem(void);
int mostrarPersonagens(void);
int iniciarCombate(void);
int OrdemCombate(void);
