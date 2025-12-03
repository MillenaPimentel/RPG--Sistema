#ifndef RPG_H
#define RPG_H 
#define MAX_PERSONAGENS 50

typedef struct{
    char nome[16];
    int nivel;  // 1 a 20
    int dado;  // d4, d6, d8, d10, d12 ou d20 
    int iniciativa;  // nível + rolagem
} Personagem;

int escolherDado();
int rolarDado(int dado);
void adicionarArquivo(int *qtd, Personagem *lista);
void salvarPersonagens(int qtd, Personagem *lista);
void carregarArquivo(int *qtd, Personagem *lista);
void criarPersonagem(Personagem *lista, int *qtd);
void editarPersonagem(Personagem *lista, int *qtd);
void removerPersonagem(Personagem *lista, int *qtd);
void listarPersonagens(Personagem *lista, int qtd);
void calcularIniciativa(Personagem *lista, int qtd);
void ordenar(Personagem *lista, int qtd, int metodoOrdenacao);

void selecionarMetodoOrdenacao(int *metodoOrdenacao);
void exibirOrdemDeAcao(Personagem lista[], int qtd);
void loopCombate(Personagem lista[], int *qtd, int *metodoOrdenacao);
int  menuPrincipal();

#endif
