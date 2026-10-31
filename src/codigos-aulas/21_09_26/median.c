#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

int main() {
    srand(time(NULL));
    int vetor[N];
    float median;

    for (int i = 0; i<N; i++) {
        vetor[i] = 1 + rand() % 10;
    }

    puts("Vetor não ordenado: ");
    for (int i = 0; i<N; i++) {
        printf("%i ", vetor[i]);
    }


    for (int i = 0; i<N; i++) {
        for (int k = 0; k<(N-1); k++) {
            int temp;
            if (vetor[k] > vetor[k+1]) {
               temp = vetor[k+1];
               vetor[k+1] = vetor[k];
               vetor[k] = temp;

            }
        }
    }

    puts("\nVetor ordenado: ");
    for (int i = 0; i<N; i++) {
        printf("%i ", vetor[i]);
    }

    if (N % 2) {
        median = vetor[ (int) (N / 2)];
    } else {
        int pos_central_1 = (int) N / 2;
        int pos_central_2 = pos_central_1 - 1;
        median = (float)  (vetor[pos_central_1] + vetor[pos_central_2]) / 2;
    }

    printf("\nMediana do vetor: %.3f\n", median);
    return 0;
}
