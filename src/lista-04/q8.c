#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main() {
    srand(time(NULL));
    int inicio, fim;
    int *vetor1 = malloc(TAM * sizeof(int));
    int *vetor2 = malloc(TAM * sizeof(int));


    if (vetor1 == 0 || vetor2 == 0) {
        puts("Sem memória suficiente!");
        exit(1);
    }

    puts("Insira o ínicio do intervalo: ");
    scanf("%i", &inicio);

    puts("Insira o ínicio do intervalo: ");
    scanf("%i", &fim);


    for (int i = 0; i < TAM; i++) {
        vetor1[i] = rand() % (fim - inicio + 1) + inicio;
        vetor2[i] = vetor1[i];
    }

    puts("\nVetor: ");
    for (int i = 0; i < TAM; i++) {
        printf("%i ", vetor1[i]);
    }
    puts("");

    // Bubble Sort
    unsigned char trocou;
    for (int i = 0; i < TAM - 1; i++) {
        int temp;
        trocou = 0;
        for (int j = 0; j < TAM - 1; j++) {
            if (vetor1[j] > vetor1[j+1]) {
                temp = vetor1[j];
                vetor1[j] = vetor1[j+1];
                vetor1[j+1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break;
    }

    // Selection Sort
    for (int i = 0; i < TAM - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < TAM; j++) {
            if (vetor2[j] < vetor2[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor2[i];
            vetor2[i] = vetor2[menor];
            vetor2[menor] = temp;
        }
    }

    puts("Vetor ordenado com bubble sort: ");
    for (int i = 0; i < TAM; i++) {
        printf("%i ", vetor1[i]);
    }
    puts("");

    puts("Vetor ordenado com selection sort: ");
    for (int i = 0; i < TAM; i++) {
        printf("%i ", vetor2[i]);
    }
    puts("");


    free(vetor1);
    free(vetor2);

    return 0;
}
