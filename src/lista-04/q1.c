#include <stdio.h>


#define TAM 15

int main() {
    float vetor[TAM];
    float maior, menor, soma;

    for (int i = 0; i < TAM; i++) {
        printf("Insira o %iº valor do vetor: ", i+1);
        scanf("%f", &vetor[i]);
        if (i == 0) {
            maior = menor = vetor[i];
        } else {
            if (vetor[i] > maior) {
                maior = vetor[i];
            } if (vetor[i] < menor) {
                menor = vetor[i];
            }
        }
    }
    soma = maior + menor;
    printf("O maior valor é %.4f\n", maior);
    printf("O menor valor é %.4f\n", menor);
    printf("A soma do menor com o maior é %.4f\n", soma);

    return 0;

}
