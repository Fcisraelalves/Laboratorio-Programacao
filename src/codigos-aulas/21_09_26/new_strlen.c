#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    char string[255];

    puts("Insira uma string: ");
    scanf("%s", string);

    int tam1, tam2 = 0;
    int i = 0;
    tam1 = strlen(string);

    while(string[i] != '\0') {
        tam2++;
        i++;
    }

    printf("Tamanho calculado com o strlen: %i\n", tam1);
    printf("Tamanho calculado manualmente: %i\n", tam2);


    return 0;
}
