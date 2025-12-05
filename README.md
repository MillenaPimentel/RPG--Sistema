# RPG - Sistema de Gerenciamento de Iniciativa

Este projeto implementa um sistema de gerenciamento de turnos para personagens em um combate de RPG, desenvolvido em linguagem C como trabalho acadêmico da disciplina **Estrutura de Dados I**.

O sistema simula a mecânica de iniciativa de jogos RPG: a cada turno, a ordem de ação dos personagens é recalculada com base no nível e em um dado de iniciativa, e os personagens são ordenados conforme o valor obtido.

---

## Funcionalidades

✅ Cadastro de personagens (nome, nível, dado)  
✅ Lista estática com limite de até 50 personagens  
✅ Sorteio automático de iniciativa por turno  
✅ Escolha de método de ordenação (Quick Sort ou Insertion Sort)  
✅ Exibição da ordem de ação a cada turno  
✅ Adição e remoção de personagens durante o combate  
✅ Execução em ciclos de turnos até encerramento manual  

---

## Estrutura do Personagem

Cada personagem possui:

| Atributo | Descrição |
|----------|----------|
| `nome` | Nome do personagem |
| `nivel` | Valor de 1 a 20 |
| `dado` | Tipo de dado (d4, d6, d8, d10, d12 ou d20) |
| `iniciativa` | Soma do nível com a rolagem do dado |

---

## Cálculo da Iniciativa

A cada novo turno:


iniciativa = nivel + rolagem do dado

## Métodos de Ordenação

A ordenação sempre ocorre em ordem decrescente de iniciativa e o usuário pode escolher qual algoritmo de ordenação utilizar durante a execução:

# Quick Sort

- Algoritmo eficiente (complexidade média O(n log n))
- Realiza partições recursivas no vetor
- É in-place: não precisa de vetor extra grande (usa só recursão)
- Ideal pra quando a lista pode crescer (se um dia quisermos mudar de 50 para 500 personagens)
  
# Insertion Sort
- Algoritmo simples
- Eficiente para listas pequenas
- Fácil de compreender e implementar

No nosso sistema de iniciativa, trabalhamos com uma lista estática de até 50 personagens, cuja ordem é recalculada várias vezes ao longo do combate. Por isso escolhemos dois algoritmos com características complementares:

• Quick Sort, que tem complexidade média O(n log n), é eficiente para dados aleatórios e trabalha in-place, sendo adequado para reordenar a lista de iniciativas a cada turno.

• Insertion Sort, que tem complexidade O(n²), mas para listas pequenas como a nossa é rápido na prática e muito simples de implementar e entender. Ele representa bem a classe dos algoritmos quadráticos e permite comparar, de forma didática, o impacto da complexidade em relação ao Quick Sort.
Considerando o tamanho máximo da lista (50 elementos), ambos funcionam bem, mas do ponto de vista teórico e escalável, o Quick Sort é o mais indicado.
  
## Fluxo de Execução
1. Cadastrar personagens
2. Escolher método de ordenação
3. Iniciar combate
4. Sistema rola os dados automaticamente
5. Personagens são ordenados por iniciativa
6. Menu permite:
- adicionar personagem
- remover personagem
- avançar turno
- trocar método
- encerrar combate

Aplicação Acadêmica
- Este projeto foi desenvolvido para praticar:
- Estruturas de Dados (listas e vetores)
- Funções e modularização
- Uso de ponteiros
- Algoritmos de ordenação
- Manipulação de strings
- Entrada de dados do usuário
- Organização de projeto em múltiplos arquivos

Integrantes do Grupo

- Millena Costa Pimentel 
- Rodrigo Frota Telles da Silva
- Letícia Barbosa Taveira
