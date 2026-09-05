#include <stdio.h>

int main() {

    int horas,minutos, segundos;

    puts("Insira a quantidade de horas: ");
    scanf("%i", &horas);

    puts("Insira a quantidade de minutos: ");
    scanf("%i", &minutos);

    puts("Insira a quantidade de segundos: ");
    scanf("%i", &segundos);

    printf("%i hora(s), %i minuto(s), %i segundos(s) => ", horas, minutos, segundos);
    segundos += horas * 3600 + minutos * 60;

    printf("Total em segundos: %is\n", segundos);
    return 0;
}
