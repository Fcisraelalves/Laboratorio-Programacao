#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned char sinal_8b;
    unsigned char sinal_4b;
    unsigned char sinal_reconstruido;
    unsigned char erro;
    int erro_acumulado = 0;
    float erro_medio;
    unsigned char mask = 240;
    int n;

    puts("Insira a quantidade de amostras do sinal: ");
    if (scanf("%i", &n) != 1 || n <= 0) {
        puts("A quantidade de amostras deve ser um inteiro maior que zero.");
        return 1;
    }

    for (int i = 0; i<n; i++) {
        puts("Insira um sinal: ");
        scanf("%hhu", &sinal_8b);

        sinal_4b = (sinal_8b & mask) >> 4;
        printf("Sinal de 8 bits: %hhu\n", sinal_8b);
        printf("Sinal de 4 bits: %hhu\n", sinal_4b);
        sinal_reconstruido = sinal_4b << 4;
        printf("Sinal reconstrúido: %hhu\n", sinal_reconstruido);

        erro = abs(sinal_8b - sinal_reconstruido);
        printf("Erro de conversão: %hhu\n", erro);
        erro_acumulado += erro;

    }

    erro_medio = (float) erro_acumulado / n;

    printf("Erro médio de quantização: %.2f\n", erro_medio);
    return 0;
}
