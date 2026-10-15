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
    int *y = malloc(TAM * sizeof(int));
    int *m = calloc(N * N, sizeof(int));

    if (x == 0 || y == 0 || m == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    for (int i = 0; i < TAM; i++) {
        *(x+i) = rand() % N;
    }

    for (int i = 0; i < TAM; i++) {
        *(y+i) = rand() % N;
    }

    for (int i = 0; i < TAM; i++) {
        (*(m + *(y+i) * N + *(x+i)))++;
    }

    printf("X = ");
    printv(x, TAM);
    printf("Y = ");
    printv(y, TAM);

    puts("M =");
    for (int i = 0; i < N; i++) {
        printv(m + i * N, N);
    }

    free(x);
    free(y);
    free(m);

    return 0;

}
