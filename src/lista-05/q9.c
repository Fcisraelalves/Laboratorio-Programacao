#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void printv(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%i ", *(v+i));
    }
    puts("");
}

int main() {
    srand(time(NULL));
    int *v = malloc(TAM * sizeof(int));

    if (v == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    for (int i = 0; i < TAM; i++) {
        *(v+i) = rand() % 11;
    }

    puts("Vetor não ordenado: ");
    printv(v, TAM);

    unsigned char trocou = 0;
    for (int i  = 0; i<(TAM-1); i++) {
        trocou = 0;
        for (int j = 0; j<(TAM-1); j++) {
            if (*(v+j) > *(v+j+1)) {
                *(v+j) = *(v+j) ^ *(v+j+1);
                *(v+j+1) = *(v+j+1) ^ *(v+j);
                *(v+j) = *(v+j) ^ *(v+j+1);
                trocou = 1;
            }
        }
        if (trocou == 0) {
            break;
        }
    }

    puts("Vetor ordenado: ");
    printv(v, TAM);

    free(v);

    return 0;

}
