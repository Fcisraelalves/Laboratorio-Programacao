#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 100


int main() {
    char *str1, *str2;
    int qtd_iguais = 0;
    int sao_iguais;

    str1 = malloc(LIMITE * sizeof(char));
    str2 = malloc(LIMITE * sizeof(char));

    if (str1 == 0 || str2 == 0) {
        puts("Sem memória suficiente!");
        exit(1);
    }

    puts("Insira a primeira string: ");
    fgets(str1, LIMITE, stdin);

    puts("Insira a segunda string: ");
    fgets(str2, LIMITE, stdin);

    if (strlen(str1) == strlen(str2)) {
        for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
            if (str1[i] == str2[i]) {
                qtd_iguais++;
            }
        }
    }

    sao_iguais = strcmp(str1, str2);
    (sao_iguais == 0) ? puts("com strcomp: As strings são iguais!") : puts("com strcomp: As strings não são iguais!");
    (qtd_iguais == strlen(str1)) ? puts("sem strcomp: As strings são iguais!") : puts("sem strcomp: As strings não são iguais!");

    free(str1);
    free(str2);

    return 0;
}
