#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numero = malloc(sizeof(int));
    int *menor = malloc(sizeof(int));

    int count = 0;

    if (numero == 0 || menor == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    printf("Insira a quantidade de números que você deseja ler: ");
    scanf("%i", &count);

    for (int i = 0; i<count; i++) {
        printf("Insira um número: ");
        scanf("%i", numero);

        if (i == 0) {
            *menor = *numero;
        } else {
          if (*numero < *menor) {
            *menor = *numero;
          }
        }

        printf("Menor valor digitado: %i\n", *menor);
    }

    free(numero);
    free(menor);
    return 0;
}
