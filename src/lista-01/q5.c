#include <stdio.h>

int main() {

    unsigned char sexo;
    float altura, peso_ideal;

    puts("Insira o seu sexo: ");
    scanf("%c", &sexo);

    puts("Insira a sua altura: ");
    scanf("%f", &altura);
    if ((sexo == 'm' || sexo == 'f') && (altura > 0 && altura < 2.5)) {
        peso_ideal = (sexo == 'm') ? 72.7 * altura - 58 : 62.1 * altura - 44.7;
        printf("Peso ideal: %.2fkg\n", peso_ideal);
    } else puts("Informações inválidas!\n");

    return 0;
}
