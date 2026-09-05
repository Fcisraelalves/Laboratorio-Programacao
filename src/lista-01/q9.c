#include <stdio.h>

int main() {

    float largura, comprimento, altura, volume;

    puts("Insira a largura da caixa: ");
    scanf("%f", &largura);

    puts("Insira o comprimento da caixa: ");
    scanf("%f", &comprimento);

    puts("Insira a altura da caixa: ");
    scanf("%f", &altura);

    volume = largura * comprimento * altura;

    printf("Volume da caixa: %.2f\n", volume);

    return 0;
}
