#include <stdio.h>
#include <stdlib.h>

#define TAM 5
int main() {

    //Pude observar que alterar o tipo de dado altera a razão da sequência de endereços de memória.
    unsigned char *v = malloc(TAM * sizeof(unsigned char));

    if (v == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    for (int i = 0; i<TAM; i++) {
        printf("Insira um valor para a posição %i: ", i);
        scanf("%hhu", (v+i));
    }

    puts("");
    for (int i = 0; i<TAM; i++) {
        printf("Valor: %hhu, Endereço: %p\n", *(v+i), (v+i));
    }

    free(v);
    return 0;
}
