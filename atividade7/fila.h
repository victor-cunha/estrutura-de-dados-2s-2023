#ifndef FILA_H
#define FILA_H

// Estrutura da fila
typedef struct {
    int capacidade;
    int tamanho;
    char** itens;
    int inicio;
    int fim;
} Fila;

Fila* criarFila(int capacidade);
void enfileirar(Fila* fila, char* item);
char* desenfileirar(Fila* fila);
void destruirFila(Fila* fila);

#endif