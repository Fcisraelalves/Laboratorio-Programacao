#include <stdio.h>

int main() {
    unsigned char matriz[3][3];

    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            printf("Insira o valor da posição [%i][%i]: ", i, j);
            scanf("%hhu", &matriz[i][j]);
        }
    }
    puts("\nMatriz: \n");
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            printf("%i ", matriz[i][j]);
        }
        puts("\n");
    }

    puts("Elementos da diagonal principal: \n");
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            if (i == j) printf("%i ", matriz[i][j]);
        }
    }

    return 0;
}
