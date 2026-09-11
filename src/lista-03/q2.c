#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a1, a2, ax, p1, p2, px, v1, v2;
    int vx;
    double dax, dpx, dvx, d1x, d2x;
    int n;

    puts("Insira a área do centróide C1: ");
    scanf("%lf", &a1);

    puts("Insira o perímetro  centróide C1: ");
    scanf("%lf", &p1);

    puts("Insira o número de vértices do centróide C1: ");
    scanf("%lf", &v1);

    printf("Características: (%.2f, %.2f, %.2f)\n", a1, p1, v1);

    puts("Insira a área do centróide C2: ");
    scanf("%lf", &a2);

    puts("Insira o perímetro  centróide C2: ");
    scanf("%lf", &p2);

    puts("Insira o número de vértices do centróide C2: ");
    scanf("%lf", &v2);

    printf("Características: (%.2f, %.2f, %.2f)\n", a2, p2, v2);

    puts("Insira a quantidade de amostras que deseja analisar: ");
    scanf("%i", &n);

    for (int i = 1; i<=n; i++) {
        printf("Insira a área da %iª amostra: ", i);
        scanf("%lf", &ax);

        printf("Insira o perímetro da %iª amostra: ", i);
        scanf("%lf", &px);

        printf("Insira o número de vértices da %iª amostra: ", i);
        scanf("%i", &vx);

        printf("Características: (%.2f, %.2f, %i)\n", ax, px, vx);

        dax = fabs(a1 - ax);
        dpx = fabs(p1 - px);
        dvx = fabs(v1 - vx);

        if (dpx >= dax && dpx >= dvx) {
            d1x = dpx;
        } else if (dvx >= dax && dvx >= dpx) {
            d1x = dvx;
        } else {
            d1x = dax;
        }

        dax = fabs(a2 - ax);
        dpx = fabs(p2 - px);
        dvx = fabs(v2 - vx);

        if (dpx >= dax && dpx >= dvx) {
            d2x = dpx;
        } else if (dvx >= dax && dvx >= dpx) {
            d2x = dvx;
        } else {
            d2x = dax;
        }

        puts("Resultado para a amostra: ");
        if (d1x == d2x) {
            puts("Falha! o modelo não conseguiu classificar a amostra\n");
        } else (d1x < d2x) ? printf("Classe 1 - Distância: %.2f\n", d1x) : printf("Classe 2 - Distância: %.2f\n", d2x);
    }
}
