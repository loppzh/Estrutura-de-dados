//  HUGO LOPES - Atividade:  FUP que armazene dez palavras em um vetor e exiba todos os caracteres desse vetor.DORMIR


#include <stdio.h>

int main() {
    char palavras[10][50];

    printf("Por favor, digite 10 palavras:\n");

    for(int i = 0; i < 10; i++) {
        printf("Palavra %d: ", i + 1);
        scanf("%49s", palavras[i]); 
    }

    printf("\nOs caracteres armazenados no vetor sao:\n");

    for(int i = 0; i < 10; i++) {
        printf("Caracteres da palavra %d: ", i + 1);
        
        for(int j = 0; palavras[i][j] != '\0'; j++) {
            
            printf("'%c' ", palavras[i][j]); 
            
        }
        printf("\n"); 
    }

    return 0;
}