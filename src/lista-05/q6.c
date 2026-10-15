#include <stdio.h>
#include <stdlib.h>
#define T_MAX 128
int main() {

    unsigned char *s = malloc(T_MAX * sizeof(unsigned char));
    unsigned char *s_copia = malloc(T_MAX * sizeof(unsigned char));

    if (s == 0 || s_copia == 0) {
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
        *(s_copia + i) = *(s+i);
    }

    printf("String original: %s\n", s);
    printf("String copiada: %s\n", s_copia);

    free(s);
    free(s_copia);

    return 0;

}
