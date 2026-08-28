#include <stdio.h>

int main() {

    int numero;
    puts("Insira um número inteiro: ");
    scanf("%i", &numero);
    printf("Triplo: %i\n", numero*3);
    printf("Dobro: %i\n", numero*2);
    printf("Meio: %.4f\n", (float) numero/2);

    return 0;
}
