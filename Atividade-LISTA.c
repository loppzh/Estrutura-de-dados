#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    char nome[50];
    int idade;
    float renda;
    bool prioritario;
} Pessoa;

typedef struct {
    Pessoa dados[MAX]; 
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

bool filaVazia(Fila *f) {
    return f->inicio == -1;
}

bool filaCheia(Fila *f) {
    return (f->fim + 1) % MAX == f->inicio;
}

bool inserir(Fila *f, Pessoa p) {
    if (filaCheia(f)) {
        return false;
    }
    
    if (filaVazia(f)) {
        f->inicio = 0;
    }
    
    f->fim = (f->fim + 1) % MAX;
    
    f->dados[f->fim] = p; 
    
    return true;
}

bool remover(Fila *f, Pessoa *p) {
    if (filaVazia(f)) {
        return false;
    }
    
    *p = f->dados[f->inicio]; 
    
    if (f->inicio == f->fim) {
        f->inicio = -1;
        f->fim = -1;
    } else {
        f->inicio = (f->inicio + 1) % MAX;
    }
    
    return true;
}

void listar(Fila *f) {
    if (filaVazia(f)) {
        printf("\nA fila esta vazia!\n");
        return;
    }

    Fila filaAuxiliar;
    inicializarFila(&filaAuxiliar);
    Pessoa temp;

    printf("\n--- Elementos na Fila (Inicio -> Fim) ---\n");
    
    while (!filaVazia(f)) {
        remover(f, &temp);
        printf("Nome: %-15s | Idade: %2d | Renda: %.2f | Prioritario: %s\n", 
               temp.nome, temp.idade, temp.renda, temp.prioritario ? "Sim" : "Nao");
        inserir(&filaAuxiliar, temp);
    }
    printf("-----------------------------------------\n");

    while (!filaVazia(&filaAuxiliar)) {
        remover(&filaAuxiliar, &temp);
        inserir(f, temp);
    }
}

int main() {
    Fila minhaFila;
    inicializarFila(&minhaFila);
    
    int opcao;
    Pessoa novaPessoa;
    Pessoa pessoaRemovida;
    int respPrioridade;

    do {
        printf("\n======== MENU DA FILA ========\n");
        printf("1. Inserir pessoa\n");
        printf("2. Retirar pessoa (Fazer a fila andar)\n");
        printf("3. Listar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Inserir Nova Pessoa ---\n");
                printf("Nome: ");
                scanf(" %[^\n]", novaPessoa.nome); 
                printf("Idade: ");
                scanf("%d", &novaPessoa.idade);
                printf("Renda: ");
                scanf("%f", &novaPessoa.renda);
                printf("Prioritario? (1 para Sim / 0 para Nao): ");
                scanf("%d", &respPrioridade);
                
                novaPessoa.prioritario = (respPrioridade == 1);
                
                if (inserir(&minhaFila, novaPessoa)) {
                    printf("\n>>> '%s' entrou na fila.\n", novaPessoa.nome);
                } else {
                    printf("\nErro: A fila esta cheia!\n");
                }
                break;

            case 2:
                if (remover(&minhaFila, &pessoaRemovida)) {
                    printf("\n>>> A fila andou! '%s' foi atendido(a) e saiu da fila.\n", pessoaRemovida.nome);
                } else {
                    printf("\nErro: A fila esta vazia! Nao ha ninguem para atender.\n");
                }
                break;

            case 3:
                listar(&minhaFila);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}