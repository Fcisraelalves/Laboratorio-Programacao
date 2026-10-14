#include <stdio.h>
#include <stdlib.h>

int main() {


    int *n1 = malloc(sizeof(int));
    int *n2 = malloc(sizeof(int));
    int *soma = malloc(sizeof(int));

    if (n1 == 0 || n2 == 0 || soma == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    puts("Insira o primeiro número: ");
    scanf("%i", n1);
    puts("Insira o segundo número: ");
    scanf("%i", n2);

    *soma = *n1 + *n2;


    printf("Valor da soma: %i\n", *soma);
    printf("Endereço de memória: %p\n", soma);

    free(n1);
    free(n2);
    free(soma);

    return 0;
}
