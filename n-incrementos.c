#include <stdio.h>

int main() {
    int n;

    // --- Caso 1: Pré-incremento (++n) ---
    n = 5;
    printf("Pre-incremento (++n):\n");
    printf("Valor original: %d\n", n);
    // Primeiro incrementa, depois entrega o valor para o printf
    printf("Valor durante o printf: %d\n", ++n); 
    printf("Valor final: %d\n\n", n);

    // --- Caso 2: Pós-incremento (n++) ---
    n = 5;
    printf("Pos-incremento (n++):\n");
    printf("Valor original: %d\n", n);
    // Primeiro entrega o valor para o printf, depois incrementa
    printf("Valor durante o printf: %d\n", n++); 
    printf("Valor final: %d\n", n);

    return 0;
}