#include <stdio.h>
#include <stdlib.h>

#define T_MAX 128

int main() {

    char *s = malloc(T_MAX * sizeof(char));
    char caractere;

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

    printf("Insira um caractere para buscar na string: ");
    scanf("%c", &caractere);

    char *p_caractere = 0;
    for (int i = 0; *(s+i) != '\0'; i++) {
        if (*(s+i) == caractere) {
            p_caractere = (s+i);
            break;
        }
    }

    if (p_caractere == 0) {
        puts("O caractere não foi encontrado na string!");
    } else {
        printf("Endereço de memória da primeira ocorrência: %p\n", p_caractere);
    }

    free(s);
    return 0;

}
