// HUGO LOPES - Atividade: FUP que solicite e armazene na memória 10 inteiros, depois, escreva-os.


#include <stdio.h>

int main() {
    int numeros[10]; 

    printf("Por favor, digite 10 numeros inteiros:\n");

    for(int i = 0; i < 10; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nOs numeros que armazenou na memoria foram:\n");

    for(int i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    
    printf("\n");

    return 0;
}