#include <stdio.h>
#include <stdlib.h>

int main() {

    int *n1 = malloc(sizeof(int));
    int *n2 = malloc(sizeof(int));

    if (n1 == 0 || n2 == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    puts("Insira o primeiro número: ");
    scanf("%i", n1);
    puts("Insira o segundo número: ");
    scanf("%i", n2);

    puts("\nAntes da substituição: \n");
    printf("Valor do primeiro número: %i\n", *n1);
    printf("Valor do primeiro número: %i\n", *n2);

    *n1 = *n1 ^ *n2;
    *n2 = *n2 ^ *n1;
    *n1 = *n1 ^ *n2;

    puts("\nDepois da substituição: \n");
    printf("Valor do primeiro número: %i\n", *n1);
    printf("Valor do primeiro número: %i\n", *n2);


    free(n1);
    free(n2);

    return 0;
}
