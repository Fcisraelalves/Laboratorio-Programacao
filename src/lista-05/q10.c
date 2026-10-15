#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define N 7

void printv(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%i ", *(v+i));
    }
    puts("");
}

int main() {
    srand(time(NULL));
    int *x = malloc(TAM * sizeof(int));
    int *ocorrencias = calloc(N, sizeof(int));

    if (x == 0 || ocorrencias == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    for (int i = 0; i < TAM; i++) {
        *(x+i) = rand() % N;
    }
    int valor_atual;
    for (int i = 0; i < TAM; i++) {
        int valor_atual = *(x+i);
        *(ocorrencias + valor_atual) = *(ocorrencias + valor_atual) + 1;

    }

    puts("Vetor gerado: ");
    printv(x, TAM);

    puts("Vetor de ocorrências");
    printv(ocorrencias, N);

    free(x);
    free(ocorrencias);

    return 0;

}
