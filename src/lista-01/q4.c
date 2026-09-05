#include <stdio.h>

int main () {
    float valor_conta;

    puts("Insira o valor da conta: ");
    scanf("%f", &valor_conta);

    printf("Valor da conta: %.2f\nAcréscimo do garçom: %.2f\nValor total: %.2f\n", valor_conta, valor_conta * 0.1, valor_conta * 1.1);
    return 0;
}
