#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    unsigned char mask;
    unsigned char armarios = 0;
    unsigned char option = 0;
    unsigned char armario;

    while (option != 3) {
        mask = 1;
        puts("\nInsira uma opção: \n[1] Ocupar armário aleatório\n[2] Liberar armário\n[3] Sair\nQualquer outro número será ignorado.");
        scanf("%hhu", &option);

        switch (option) {
            case 3:
                puts("\nEncerrando...");
                break;
            case 1:
                if (armarios == 255) {
                    puts("\nTodos os armários já estão ocupados!");
                } else {
                    do {
                        mask = 1;
                        mask = mask << rand() % 8;
                    } while (((armarios & mask) == mask));
                    armarios = armarios | mask;
                }

                break;
            case 2:
                puts("\nInsira o número do armário a ser desocupado (0-7): ");
                scanf("%hhu", &armario);
                if (armario <= 7 && armario >= 0) {
                    mask = mask << (armario);
                    armarios = armarios & ~mask;
                }
                break;
            default:
                puts("\nNúmero inválido...");
        }
        mask = 128;
        printf("\nMapeamento de Armários: %hhu\n", armarios);
        for (int i = 7; i >= 0; i--) {
            printf("%i", ((armarios & mask) == mask ? 1 : 0));
            mask = mask >> 1;
        }
    }
    return 0;
}
