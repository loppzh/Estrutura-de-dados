//  HUGO LOPES - Atividade: FUP que solicite dois números, e apresente os números e a soma dos números. Utilize uma função que receba os números por parâmetro e retorne a soma para o programa.
  

#include <stdio.h>

float calcularSoma(float a, float b) {
    return a + b;
}

int main() {
    float num1, num2, resultado;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    resultado = calcularSoma(num1, num2);

    printf("\nNumeros informados: %.2f e %.2f\n", num1, num2);
    printf("A soma dos numeros e: %.2f\n", resultado);

    return 0;
}