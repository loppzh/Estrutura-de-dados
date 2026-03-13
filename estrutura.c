// ALUNO: Hugo Lopes 

#include <stdio.h>

struct lista {
    char nome[100];
    int dia;
    int mes;
    int ano;
} list_aniv; 

int main() {
    struct lista pessoa[100]; 
    int quantidade;

    printf("Quantas pessoas deseja cadastrar? (Max 100): ");
    scanf("%d", &quantidade);

    for(int i = 0; i < quantidade; i++) {
        printf("\n--- Cadastro da pessoa %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf(" %99[^\n]", pessoa[i].nome); 

        printf("Dia do nascimento: ");
        scanf("%d", &pessoa[i].dia);

        printf("Mes do nascimento: ");
        scanf("%d", &pessoa[i].mes);

        printf("Ano do nascimento: ");
        scanf("%d", &pessoa[i].ano);
    }

    printf("\n===================================\n");
    printf("      LISTA DE ANIVERSARIANTES       \n");
    printf("===================================\n");

    for(int i = 0; i < quantidade; i++) {
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Data de Nasc.: %02d/%02d/%d\n", pessoa[i].dia, pessoa[i].mes, pessoa[i].ano);
        printf("-----------------------------------\n");
    }

    return 0;
}