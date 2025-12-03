#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rpg.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int escolherDado() {
    int opcao;

    do {
        printf("\nEscolha o dado de iniciativa:\n");
        printf("1 - d4\n");
        printf("2 - d6\n");
        printf("3 - d8\n");
        printf("4 - d10\n");
        printf("5 - d12\n");
        printf("6 - d20\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        if (opcao < 1 || opcao > 6) {
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao < 1 || opcao > 6);

    if (opcao == 1) return 4;
    if (opcao == 2) return 6;
    if (opcao == 3) return 8;
    if (opcao == 4) return 10;
    if (opcao == 5) return 12;
    return 20; 
}

int rolarDado(int lados) {
    return (rand() % lados) + 1;
}

void calcularIniciativa(Personagem *lista, int qtd) {
    for (int i = 0; i < qtd; i++) {
        int dado = rolarDado(lista[i].dado);
        lista[i].iniciativa = lista[i].nivel + dado;

        printf("%s rolou d%d = %d | Iniciativa = %d\n",
               lista[i].nome,
               lista[i].dado,
               dado,
               lista[i].iniciativa);
    }
}

void listarPersonagens(Personagem *lista, int qtd) {
    if (qtd == 0) {
        printf("\nNenhum personagem cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Personagens (%d) ---\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("%d) Nome: %s | Nivel: %d | Dado: d%d | Iniciativa atual: %d\n",
               i + 1,
               lista[i].nome,
               lista[i].nivel,
               lista[i].dado,
               lista[i].iniciativa);
    }
}


void salvarPersonagens(int qtd, Personagem *lista){
    FILE *arquivo = fopen("personagens.txt", "w");
    if (arquivo == NULL){
        printf("Parece ter algo errado com o seu arquivo :( .");
    return;
    }
    else{

    
        for (int i = 0; i < qtd; i++){
            fprintf(arquivo, "%s;%d;%d;%d\n", lista[i].nome, lista[i].nivel, lista[i].dado, lista[i].iniciativa);

        }
        fclose(arquivo);
        return;
    }
}

void criarPersonagem(Personagem *lista, int *qtd) {
    if (*qtd >= MAX_PERSONAGENS) {
        printf("\nLista cheia! Nao e possivel adicionar mais personagens.\n");
        return;
    }

    Personagem p;

    printf("\n--- Criar novo personagem ---\n");
    printf("Nome (sem espacos ou use _): ");
    scanf("%15s", p.nome);
    limparBuffer();

    do {
        printf("Nivel (1 a 20): ");
        scanf("%d", &p.nivel);
        limparBuffer();
        if (p.nivel < 1 || p.nivel > 20) {
            printf("Nível inválido! Digite um valor entre 1 e 20.\n");
        }
    } while (p.nivel < 1 || p.nivel > 20);

    p.dado = escolherDado();
    p.iniciativa = 0;

    lista[*qtd] = p;
    (*qtd)++;
    salvarPersonagens(*qtd, lista);

    printf("Personagem criado com sucesso!\n");
}

void adicionarArquivo(int *qtd, Personagem *lista) {
    if (*qtd >= MAX_PERSONAGENS) {
        printf("Voce atingiu o maximo de personagens (%d/%d).\n", *qtd, MAX_PERSONAGENS);
        return;
    }

    char nomeArquivo[100];
    printf("\n--- Importar Arquivo ---\n");
    printf("Digite o nome do arquivo (ex: personagens.txt): ");
    scanf("%99s", nomeArquivo);
    limparBuffer();
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro: Parece ter algo de errado com o arquivo :( '%s'. Verifique o nome.\n", nomeArquivo);
        return;
    }
    int personagensImportados = 0;
    while (*qtd < MAX_PERSONAGENS && 
           fscanf(arquivo, "%49[^;];%d;%d;%d\n", 
                  lista[*qtd].nome, 
                  &lista[*qtd].nivel, 
                  &lista[*qtd].dado, 
                  &lista[*qtd].iniciativa) == 4) {
        (*qtd)++;
        personagensImportados++;
    }

    fclose(arquivo);

    if (personagensImportados > 0) {
        printf("Sucesso! %d personagens importados de '%s'.\n", personagensImportados, nomeArquivo);
        salvarPersonagens(*qtd, lista); 
    } else {
        printf("Nao ha nenhum personagem neste arquivo.\n");
    }
    salvarPersonagens(*qtd, lista);
}
    void carregarArquivo(int *qtd, Personagem *lista){
    FILE *arquivo = fopen("personagens.txt", "r");
    if (arquivo == NULL){
        printf("o arquivo parece estar vazio...");
    return;
    }
    else{
        while (*qtd < MAX_PERSONAGENS && fscanf(arquivo, "%49[^;];%d;%d;%d\n", lista[*qtd].nome, &lista[*qtd].nivel, &lista[*qtd].dado, &lista[*qtd].iniciativa) == 4){
            (*qtd)++;
        }
        fclose(arquivo);
    }
}

void removerPersonagem(Personagem *lista, int *qtd) {
    if (*qtd == 0) {
        printf("\nNenhum personagem para remover.\n");
        return;
    }
    listarPersonagens(lista, *qtd);

    int indice;
    printf("\nDigite o índice do personagem que deseja remover: ");
    scanf("%d", &indice);
    limparBuffer();

    if (indice < 1 || indice > *qtd) {
        printf("Indice invalido.\n");
        return;
    }

    indice--;

    for (int i = indice; i < *qtd - 1; i++) {
        lista[i] = lista[i + 1];
    }

    (*qtd)--;
    salvarPersonagens(*qtd, lista);
    printf("Personagem removido com sucesso.\n");
}

static void trocar(Personagem *a, Personagem *b) {
    Personagem temp = *a;
    *a = *b;
    *b = temp;
}

static int particionar(Personagem *lista, int inicio, int fim) {
    int pivo = lista[fim].iniciativa;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        // ordem decrescente
        if (lista[j].iniciativa > pivo) {
            i++;
            trocar(&lista[i], &lista[j]);
        }
    }
    trocar(&lista[i + 1], &lista[fim]);
    return i + 1;
}

static void quickSort(Personagem *lista, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(lista, inicio, fim);
        quickSort(lista, inicio, p - 1);
        quickSort(lista, p + 1, fim);
    }
}

static void insertionSort(Personagem *lista, int qtd) {
    for (int i = 1; i < qtd; i++) {
        Personagem chave = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j].iniciativa < chave.iniciativa) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = chave;
    }
}

void ordenar(Personagem *lista, int qtd, int metodoOrdenacao) {
    if (qtd <= 1) return;

    if (metodoOrdenacao == 1) {
        quickSort(lista, 0, qtd - 1);
    } else {
        insertionSort(lista, qtd);
    }
}

void selecionarMetodoOrdenacao(int *metodoOrdenacao) {
    int opcao;
    printf("\nEscolha o metodo de ordenacao:\n");
    printf("1 - Quick Sort\n");
    printf("2 - Insertion Sort\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();

    if (opcao == 1 || opcao == 2) {
        *metodoOrdenacao = opcao;
        printf("Metodo de ordenacao definido como: %s\n",
               (opcao == 1 ? "Quick Sort" : "Insertion Sort"));
    } else {
        printf("Opcao invalida. Mantendo metodo atual.\n");
    }
}

void exibirOrdemDeAcao(Personagem *lista, int qtd) {
    printf("\n--- Ordem de acao (maior iniciativa primeiro) ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d) %s | Nivel: %d | Dado: d%d | Iniciativa: %d\n",
               i + 1,
               lista[i].nome,
               lista[i].nivel,
               lista[i].dado,
               lista[i].iniciativa);
    }
}

void loopCombate(Personagem *lista, int *qtd, int *metodoOrdenacao) {
    if (*qtd == 0) {
        printf("\nNao ha personagens. Crie pelo menos um antes de iniciar o combate.\n");
        return;
    }

    int continuar = 1;
    int turno = 1;

    while (continuar) {
        printf("\n==============================\n");
        printf("          TURNO %d\n", turno);
        printf("==============================\n");

        calcularIniciativa(lista, *qtd);
        ordenar(lista, *qtd, *metodoOrdenacao);
        exibirOrdemDeAcao(lista, *qtd);

        printf("\nOpcoes do combate:\n");
        printf("1 - Adicionar personagem\n");
        printf("2 - Remover personagem\n");
        printf("3 - Avancar para o proximo turno\n");
        printf("4 - Trocar metodo de ordenacao\n");
        printf("5 - Encerrar combate e voltar ao menu principal\n");
        printf("6 - Adicionar um arquivo com personagens\n");
        printf("Opcao: ");

        int opcao;
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                criarPersonagem(lista, qtd);
                break;
            case 2:
                removerPersonagem(lista, qtd);
                if (*qtd == 0) {
                    printf("\nNao ha mais personagens, encerrando combate.\n");
                    continuar = 0;
                }
                break;
            case 3:
                turno++;
                break;
            case 4:
                selecionarMetodoOrdenacao(metodoOrdenacao);
                break;
            case 5:
                continuar = 0;
                break;
            case 6:
            adicionarArquivo(qtd, lista);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }
}

int menuPrincipal() {
    int opcao;
    printf("\n========== MENU PRINCIPAL ==========\n");
    printf("1 - Criar personagem\n");
    printf("2 - Listar personagens\n");
    printf("3 - Remover personagem\n");
    printf("4 - Selecionar método de ordenação\n");
    printf("5 - Iniciar combate\n");
    printf("6 - Adicionar um arquivo com personagens\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}
