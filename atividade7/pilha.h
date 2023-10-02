#ifndef PILHA_H
#define PILHA_H

// Estrutura da pilha
typedef struct {
    int capacidade;
    int tamanho;
    char** itens;
} Pilha;

Pilha* criarPilha(int capacidade);
void empilhar(Pilha* pilha, char* item);
char* desempilhar(Pilha* pilha);
void destruirPilha(Pilha* pilha);

#endif