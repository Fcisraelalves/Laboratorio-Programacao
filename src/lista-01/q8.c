#include <stdio.h>

int main() {

    int num;

    puts("Insira um inteiro qualquer: ");
    scanf("%i", &num);

    printf("Número: %i, Sucessor: %i, Antecessor: %i\n", num, num+1, num-1);

    return 0;
}
