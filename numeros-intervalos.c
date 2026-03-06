//HUGO LOPES - Atividade:  FUP que solicite dois números inteiros e escreva os números do intervalo.


#include <stdio.h>

int main() {
    int num1, num2;

    printf("Digite o numero inicial: ");
    scanf("%d", &num1);

    printf("Digite o numero final: ");
    scanf("%d", &num2);

    for(int i = num1; i <= num2; i++) {
        printf("%d ", i);
    }

    return 0;
}