#include <stdio.h>

int main() {
    float cotacao_dolar, valor_reais, valor_convertido;

    puts("Insira o valor da cotação atual do dolar: ");
    scanf("%f", &cotacao_dolar);

    puts("Insira o valor em reais que será convertido: ");
    scanf("%f", &valor_reais);

    valor_convertido = valor_reais / cotacao_dolar;

    printf("BRL %.2f => USD %.2f \n", valor_reais, valor_convertido);

    return 0;

}
