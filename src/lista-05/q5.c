#include <stdio.h>
#include <stdlib.h>
#define T_MAX 128
int main() {

    unsigned char *s = malloc(T_MAX * sizeof(unsigned char));
    int tamanho = 0;

    if (s == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    printf("Insira uma string: ");
    fgets(s, T_MAX, stdin);

    for(int i = 0; *(s+i) != '\0'; i++) {
        if (*(s+i) == '\n') {
            *(s+i) = '\0';
        }
    }

    for (int i = 0; *(s+i) != '\0'; i++) {
        tamanho++;
    }

    printf("Tamanho da string: %i\n", tamanho);

    free(s);

    return 0;

}
