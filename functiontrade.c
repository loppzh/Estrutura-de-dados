// Aluno - HUGO LOPES 


#include <stdio.h>

void troca(int a, int b) {
    int temp; 
    
    temp = a;
    a = b;
    b = temp;
    
    printf("Na funcao troca (invertidos): %d e %d\n", a, b);
}

int main() {
    int a, b;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    printf("\nOrdem digitada (antes da funcao): %d e %d\n", a, b);

    troca(a, b);

    printf("Apos a funcao (ordem original mantida): %d e %d\n", a, b);

    return 0;
}
