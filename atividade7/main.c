#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

// Função para limpar a tela no Windows
void limparTela() {
    system("cls");
}

// Função para listar os itens da pilha
void listarPilha(Pilha* pilha) {
    printf("Itens na pilha:\n");
    for (int i = pilha->tamanho - 1; i >= 0; i--) {
        printf("%s\n", pilha->itens[i]);
    }
}

// Função para listar os itens da fila
void listarFila(Fila* fila) {
    printf("Itens na fila:\n");
    int index = fila->inicio;
    for (int i = 0; i < fila->tamanho; i++) {
        
        printf("%s\n", fila->itens[index]);
        index = (index + 1) % fila->capacidade;
    }
}

int main() {
    Pilha* pilhaDeCompras = criarPilha(10);
    Fila* filaDeEspera = criarFila(5);
    char input[100]; // Buffer para a entrada do usuário

    while (1) { // Loop infinito
        
        printf("Escolha uma acao:\n");
        printf("1. Adicionar item a pilha\n");
        printf("2. Remover item da pilha\n");
        printf("3. Listar itens da pilha\n"); // Adicione a opção de listar pilha
        printf("4. Adicionar item a fila\n");
        printf("5. Remover item da fila\n");
        printf("6. Listar itens da fila\n"); // Adicione a opção de listar fila
        printf("7. Sair\n");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o item para adicionar a pilha: ");
                scanf("%s", input);
                empilhar(pilhaDeCompras, strdup(input)); // Use strdup para copiar a string
                break;
            case 2:
                if (pilhaDeCompras->tamanho > 0) {
                    char* itemRemovido = desempilhar(pilhaDeCompras);
                    printf("Item removido da pilha: %s\n", itemRemovido);
                    free(itemRemovido);
                } else {
                    printf("A pilha esta vazia.\n");
                }
                break;
            case 3:
                listarPilha(pilhaDeCompras);
                break;
            case 4:
                printf("Digite o item para adicionar a fila: ");
                scanf("%s", input);
                enfileirar(filaDeEspera, strdup(input)); // Use strdup para copiar a string
                break;
            case 5:
                if (filaDeEspera->tamanho > 0) {
                    char* clienteAtendido = desenfileirar(filaDeEspera);
                    printf("Cliente atendido: %s\n", clienteAtendido);
                    free(clienteAtendido);
                } else {
                    printf("A fila esta vazia.\n");
                }
                break;
            case 6:
                listarFila(filaDeEspera);
                break;
            case 7:
                // Libere a memória alocada para pilha e fila e saia do programa
                destruirPilha(pilhaDeCompras);
                destruirFila(filaDeEspera);
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("Pressione Enter para continuar...");
        while (getchar() != '\n'); // Limpa o buffer do teclado
        getchar(); // Aguarda o usuário pressionar Enter
        limparTela(); // Limpa a tela
    }

    return 0;
}


