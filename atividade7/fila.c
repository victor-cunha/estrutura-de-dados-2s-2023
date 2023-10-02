#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->itens = (char**)malloc(sizeof(char*) * capacidade);
    fila->inicio = 0;
    fila->fim = -1;
    return fila;
}

void enfileirar(Fila* fila, char* item) {
    if (fila->tamanho < fila->capacidade) {
        fila->fim = (fila->fim + 1) % fila->capacidade;
        fila->itens[fila->fim] = item;
        fila->tamanho++;
    }
}

char* desenfileirar(Fila* fila) {
    if (fila->tamanho > 0) {
        char* item = fila->itens[fila->inicio];
        fila->inicio = (fila->inicio + 1) % fila->capacidade;
        fila->tamanho--;
        return item;
    }
    return NULL; // Fila vazia
}

void destruirFila(Fila* fila) {
    free(fila->itens);
    free(fila);
}