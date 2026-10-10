#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 3
int main() {
    srand(time(NULL));
    int vetor[TAM];
    int somatorio, produtorio;
    double m_aritmetica, m_geometrica;

    somatorio = 0;
    produtorio = 1;

    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 20;
    }

    puts("Vetor: ");
    for (int i = 0; i < TAM; i++) {
        printf("%i ", vetor[i]);
    }

    for (int i = 0; i < TAM; i++) {
        somatorio += vetor[i];
        produtorio *= vetor[i];
    }

    m_aritmetica = (double) somatorio / TAM;
    m_geometrica = pow((double) produtorio, (1.0 / TAM));

    printf("\nMédia aritmética: %.4f\n", m_aritmetica);
    printf("Média geométrica: %.4f", m_geometrica);

    return 0;
}
