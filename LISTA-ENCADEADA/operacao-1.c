#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[100];
    struct No *prox;
} No;

void inserir(No **head, char *nome) {
    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (*head == NULL || strcmp((*head)->nome, nome) >= 0) {
        novo->prox = *head;
        *head = novo;
    } else {
        No *atual = *head;
        while (atual->prox != NULL && strcmp(atual->prox->nome, nome) < 0) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

void remover(No **head, char *nome) {
    No *atual = *head;
    No *anterior = NULL;

    if (atual != NULL && strcmp(atual->nome, nome) == 0) {
        *head = atual->prox;
        free(atual);
        return;
    }

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return;
    }

    anterior->prox = atual->prox;
    free(atual);
}

void listar(No *head) {
    No *atual = head;
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->prox;
    }
}

int consultar(No *head, char *nome) {
    No *atual = head;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return 1;
        }
        if (strcmp(atual->nome, nome) > 0) {
            return 0;
        }
        atual = atual->prox;
    }
    return 0;
}

int contar(No *head) {
    int contador = 0;
    No *atual = head;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    No *head = NULL; 
    int opcao;
    char nome[100];

    do {
        printf("\n=== SISTEMA DE LISTA ENCADEADA ===\n");
        printf("1. Inserir nome (Ordenado)\n");
        printf("2. Remover nome\n");
        printf("3. Listar todos\n");
        printf("4. Consultar nome\n");
        printf("5. Contar elementos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer(); 

        switch(opcao) {
            case 1:
                printf("Digite o nome para inserir: ");
                scanf(" %99[^\n]", nome);
                inserir(&head, nome);
                printf("-> '%s' inserido com sucesso!\n", nome);
                break;

            case 2:
                if (head == NULL) {
                    printf("-> A lista esta vazia.\n");
                } else {
                    printf("Digite o nome para remover: ");
                    scanf(" %99[^\n]", nome);
                    if (consultar(head, nome)) {
                        remover(&head, nome);
                        printf("-> '%s' removido com sucesso!\n", nome);
                    } else {
                        printf("-> Erro: '%s' nao encontrado na lista.\n", nome);
                    }
                }
                break;

            case 3:
                if (head == NULL) {
                    printf("\n-> A lista esta vazia.\n");
                } else {
                    printf("\n--- Elementos na Lista ---\n");
                    listar(head);
                    printf("--------------------------\n");
                }
                break;

            case 4:
                if (head == NULL) {
                    printf("-> A lista esta vazia.\n");
                } else {
                    printf("Digite o nome para consultar: ");
                    scanf(" %99[^\n]", nome);
                    if (consultar(head, nome)) {
                        printf("-> Resultado: O nome '%s' ESTA na lista.\n", nome);
                    } else {
                        printf("-> Resultado: O nome '%s' NAO ESTA na lista.\n", nome);
                    }
                }
                break;

            case 5:
                printf("-> Total de elementos na lista: %d\n", contar(head));
                break;

            case 0:
                printf("\nA encerrar o sistema...\n");
                
                while (head != NULL) {
                    No *temp = head;
                    head = head->prox;
                    free(temp);
                }
                break;

            default:
                printf("\n-> Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}