// HUGO LOPES - Atividade:  FUP que solicite 20 letras e armazene-as em um vetor, utilize uma estrutura de repetição com teste no final para entrada de dados e uma estrutura de repetição com teste no início para exibir os dados.

#include <stdio.h>

int main() {
    char letras[20];
    int i = 0; 

    printf("Por favor, digite 20 letras:\n");

    do {
        printf("Digite a letra %d: ", i + 1);
        scanf(" %c", &letras[i]); 
        i++; 
    } while (i < 20); 

    printf("\nAs letras armazenadas no vetor foram:\n");

    int j = 0; 

    while (j < 20) { 
        printf("%c ", letras[j]);
        j++; 
    }

    printf("\n");

    return 0;
}