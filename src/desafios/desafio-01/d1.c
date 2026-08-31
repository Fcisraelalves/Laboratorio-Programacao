#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    unsigned char mask = 1;
    unsigned char armario = 0;
    unsigned char option;

    while (option != 3) {
        puts("Insira uma opção: \n[1] Ocupar armário\n[2] Liberar armário\n[3] Sair\n");
        scanf("%hhu", &option);
        if (option == 1) {
            mask = 1;
            mask = mask << rand() % 9;
            armario = armario | mask;

        } else if (option == 2) {
            mask = 254;
            mask = mask << rand() % 9;
            armario = armario & mask;

        } else {
            puts("Encerrando...");
        }

        printf("%hhu\n", armario);

    }
    printf("%hhu\n", armario);

    return 0;
}
