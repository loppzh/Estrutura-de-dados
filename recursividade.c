#include <stdio.h>

int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    
    return n * fatorial(n - 1);
}

int main() {
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    resultado = fatorial(numero);

    printf("Fatorial de %d = %d\n", numero, resultado);

    return 0;
}