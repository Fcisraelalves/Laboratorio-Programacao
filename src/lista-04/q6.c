#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 100


int main() {
    char *str1;


    str1 = malloc(LIMITE * sizeof(char));

    if (str1 == 0) {
        puts("Sem memória suficiente!");
        exit(1);
    }

    puts("Insira uma string: ");
    fgets(str1, LIMITE, stdin);

    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] == '\n') str1[i] = '\0';
        i++;
    }
    printf("String normal: %s\n", str1);
    printf("String invertida: ");
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        printf("%c", str1[i]);
    }
    puts("");

    free(str1);
    return 0;
}
