#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->tamanho = 0;
    pilha->itens = (char**)malloc(sizeof(char*) * capacidade);
    return pilha;
}

void empilhar(Pilha* pilha, char* item) {
    if (pilha->tamanho < pilha->capacidade) {
        pilha->itens[pilha->tamanho] = item;
        pilha->tamanho++;
    }
}

char* desempilhar(Pilha* pilha) {
    if (pilha->tamanho > 0) {
        pilha->tamanho--;
        return pilha->itens[pilha->tamanho];
    }
    return NULL; // Pilha vazia
}

void destruirPilha(Pilha* pilha) {
    free(pilha->itens);
    free(pilha);
}
