#ifndef RPG_H
#define RPG_H 
#define MAX_PERSONAGENS 50

typedef struct{
    char nome[16];
    int nivel;  // 1 a 20
    int dado;  // d4, d6, d8, d10, d12 ou d20 
    int iniciativa;  // nível + rolagem
} Personagem;

int escolherDado(); //escolhe o tipo de dado do menu(0 a 20)
int rolarDado(int dado); //rola dado aleatório (1 a N faces)
void adicionarArquivo(int *qtd, Personagem *lista); //importa personagem de arquivo externo
void salvarPersonagens(int qtd, Personagem *lista); //salva lista em "personagens.txt"
void carregarArquivo(int *qtd, Personagem *lista); // Carrega lista do "personagens.txt" no início
void criarPersonagem(Personagem *lista, int *qtd); // Cria novo personagem via input
void editarPersonagem(Personagem *lista, int *qtd); // Edita personagem por índice
void removerPersonagem(Personagem *lista, int *qtd); // Remove personagem por índice
void listarPersonagens(Personagem *lista, int qtd); // Lista todos os personagens
void calcularIniciativa(Personagem *lista, int qtd); // Calcula iniciativa para toda a lista
void ordenar(Personagem *lista, int qtd, int metodoOrdenacao); // Ordena por iniciativa (Quick/Insertion Sort)
void selecionarMetodoOrdenacao(int *metodoOrdenacao); // Menu de escolha QuickSort/InsertionSort
void exibirOrdemDeAcao(Personagem lista[], int qtd); // Mostra ordem de ação do combate
void loopCombate(Personagem lista[], int *qtd, int *metodoOrdenacao); // Loop principal do combate RPG
int  menuPrincipal(); // Menu principal (todas as opções)

#endif
