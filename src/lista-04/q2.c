#include <stdio.h>
#include <stdlib.h>

int main() {
    char caractere;
    unsigned char tam, encontrou;
    char *pstring;

    encontrou = 0;
    puts("Insira o tamanho da string: ");
    scanf("%hhu", &tam);
    pstring = malloc((tam + 1) * sizeof(unsigned char));
    if (pstring == 0) {
        puts("Sem memória disponível!");
        exit(1);
    }

    puts("Insira uma string: ");
    scanf("%s", pstring);

    puts("Insira um caractere: ");
    scanf(" %c", &caractere);

    for (int i = 0; i < tam; i++) {
        if (pstring[i] == caractere) {
            encontrou = 1;
            break;
        }
    }

    (encontrou) ? puts("A string contém o caractere digitado!") : puts("A string não contém o caractere digitado!");
    free(pstring);

    return 0;
}
