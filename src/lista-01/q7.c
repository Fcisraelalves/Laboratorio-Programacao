#include <stdio.h>

int main() {

    int num;

    puts("Insira um inteiro qualquer: ");
    scanf("%i", &num);

    printf("Número: %i => Número ao quadrado: %i\n", num, num * num);
    return 0;
}
