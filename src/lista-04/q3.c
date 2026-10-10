#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int main() {
    char string[TAM];
    unsigned int qtd_caracteres = 0;


    puts("Insira uma string: ");
    fgets(string, TAM, stdin);

    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == '\n') string[i] = '\0';
        i++;
    }

    for (int i = 0; string[i] != '\0'; i++) {
        qtd_caracteres++;
    }

    printf("Quantidade total de caracteres na string: %i\n", qtd_caracteres);

    return 0;
}
