#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a = 0, p = 0;
    int v = 0;
    double da = 0, dp = 0, dv = 0;
    double distancia;

    for (int i = 1; i<=2; i++) {
        puts("Insira a área do objeto: ");
        scanf("%lf", &a);

        puts("Insira o perímetro do objeto: ");
        scanf("%lf", &p);

        puts("Insira o número de vértices: ");
        scanf("%i", &v);

        printf("Características: (%.2f, %.2f, %i)\n", a, p, v);

        da = (da == 0) ? da + a : fabs(da - a);
        dp = (dp == 0) ? dp + p : fabs(dp - p);
        dv = (dv == 0) ? dv + v : fabs(dv - v);
    }

    distancia = da;
    if (dp >= da && dp >= dv) {
        distancia = dp;
    } else if (dv >= da && dv >= dp) {
        distancia = dv;
    }

    printf("Distância de Chebyshev entre os vetores: %.2f\n", distancia);
    return 0;
}
