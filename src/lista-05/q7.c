#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_MAX 128

int main() {

    unsigned char *s1 = malloc(T_MAX * sizeof(unsigned char));
    unsigned char *s2 = malloc(T_MAX * sizeof(unsigned char));

    if (s1 == 0 || s2 == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    printf("Insira uma string: ");
    fgets(s1, T_MAX, stdin);

    for(int i = 0; *(s1+i) != '\0'; i++) {
        if (*(s1+i) == '\n') {
            *(s1+i) = '\0';
        }
    }

    printf("Insira uma string: ");
    fgets(s2, T_MAX, stdin);

    for(int i = 0; *(s2+i) != '\0'; i++) {
        if (*(s2+i) == '\n') {
            *(s2+i) = '\0';
        }
    }

    int t1 = strlen(s1);
    int t2 = strlen(s2);

    if ((t1 + t2) > (T_MAX - 1)) {
        puts("Não é possível realizar essa concatenação!");
    } else {
        for (int i = 0; i<t2; i++) {
            *(s1 + t1 + i) = *(s2 + i);
        }
        *(s1 + t1 + t2) = '\0';
    }

    printf("String concatenada: %s\n", s1);

    free(s1);
    free(s2);

    return 0;

}
