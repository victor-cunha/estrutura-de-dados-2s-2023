#ifndef LISTA_H
#define LISTA_H

#include "contato.h"

typedef struct lista_contatos {
//CompleteAqui//
} lista_contatos;

/** Inicializa uma lista vazia de contatos  */
void inicializar(lista_contatos *l, int capacidade);

/** Destroi a lista de contatos, liberando o espaço ocupado */
void destruir(lista_contatos *l);

/** Mostra na tela a lista de contatos */
void print_lista(lista_contatos* l);

/**
* Adiciona um elemento na lista de contatos. Retorna 1 se
* a insercao foi bem sucedida e 0 caso contrario
*/
int inserir(lista_contatos *l, contato novo);

#endif // LISTA_H