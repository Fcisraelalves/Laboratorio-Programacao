#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 100

int main() {
    char *str1, *str2, *str3;
    int i, j;

    str1 = malloc(LIMITE * sizeof(char));
    str2 = malloc(LIMITE * sizeof(char));
    str3 = malloc(LIMITE * sizeof(char));

    if (str1 == NULL || str2 == NULL || str3 == NULL) {
        puts("Sem memória suficiente!");
        free(str1);
        free(str2);
        free(str3);
        exit(1);
    }

    puts("Insira a primeira string: ");
    fgets(str1, LIMITE, stdin);

    puts("Insira a segunda string: ");
    fgets(str2, LIMITE, stdin);


    i = 0;
    while (str1[i] != '\0') {
        if (str1[i] == '\n') str1[i] = '\0';
        i++;
    }

    i = 0;
    while (str2[i] != '\0') {
        if (str2[i] == '\n') str2[i] = '\0';
        i++;
    }

    if (strlen(str1) + strlen(str2) >= LIMITE) {
        puts("As strings ultrapassam o limite!");
        free(str1);
        free(str2);
        free(str3);
        exit(1);
    }

    strcpy(str3, str1);
    strcat(str3, str2);

    printf("Com strcat: %s\n", str3);

    i = 0;
    j = 0;

    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        str3[i] = str2[j];
        i++;
        j++;
    }

    str3[i] = '\0';

    printf("Sem strcat: %s\n", str3);

    free(str1);
    free(str2);
    free(str3);

    return 0;
}
