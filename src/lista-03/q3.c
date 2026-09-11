#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int area_x, per_x, v_x, gt_x;
    int n;
    double dax, dpx, dvx, chebyshev_d1x, chebyshev_d2x;
    double manhattan_d1x, manhattan_d2x;
    double euclidian_d1x, euclidian_d2x;
    int gt_c, gt_m, gt_e;
    int acertos_m, acertos_e, acertos_c;
    float acc_c, acc_m, acc_e;

    double area_c1, per_c1, v_c1;
    double area_c2, per_c2, v_c2;

    puts("Insira a área do centróide C1: ");
    scanf("%lf", &area_c1);
    puts("Insira o perímetro do centróide C1: ");
    scanf("%lf", &per_c1);
    puts("Insira o número médio de vértices do centróide C1: ");
    scanf("%lf", &v_c1);

    puts("Insira a área do centróide C2: ");
    scanf("%lf", &area_c2);
    puts("Insira o perímetro do centróide C2: ");
    scanf("%lf", &per_c2);
    puts("Insira o número médio de vértices do centróide C2: ");
    scanf("%lf", &v_c2);

    puts("Insira a quantidade de amostras que deseja analisar: ");
    if (scanf("%i", &n) != 1 || n <= 0) {
        puts("A quantidade de amostras deve ser um inteiro maior que zero.");
        return 1;
    }

    acertos_m = acertos_e = acertos_c = 0;

    for (int i = 1; i<=n; i++) {
        printf("Insira a área da %iª amostra: ", i);
        scanf("%i", &area_x);

        printf("Insira o perímetro da %iª amostra: ", i);
        scanf("%i", &per_x);

        printf("Insira o número de vértices da %iª amostra: ", i);
        scanf("%i", &v_x);

        printf("Insira o GT da %iª amostra: ", i);
        scanf("%i", &gt_x);

        printf("Características: (%i, %i, %i)\n", area_x, per_x, v_x);

        dax = fabs(area_c1 - area_x);
        dpx = fabs(per_c1 - per_x);
        dvx = fabs(v_c1 - v_x);

        if (dpx >= dax && dpx >= dvx) {
            chebyshev_d1x = dpx;
        } else if (dvx >= dax && dvx >= dpx) {
            chebyshev_d1x = dvx;
        } else {
            chebyshev_d1x = dax;
        }

        euclidian_d1x = sqrt((dax * dax + dpx * dpx + dvx * dvx));
        manhattan_d1x = dax + dpx + dvx;

        dax = fabs(area_c2 - area_x);
        dpx = fabs(per_c2 - per_x);
        dvx = fabs(v_c2 - v_x);

        if (dpx >= dax && dpx >= dvx) {
            chebyshev_d2x = dpx;
        } else if (dvx >= dax && dvx >= dpx) {
            chebyshev_d2x = dvx;
        } else {
            chebyshev_d2x = dax;
        }

        euclidian_d2x = sqrt(dax * dax + dpx * dpx + dvx * dvx);
        manhattan_d2x = dax + dpx + dvx;
        if (chebyshev_d1x != chebyshev_d2x) gt_c = (chebyshev_d1x < chebyshev_d2x) ? 1 : 2;
        else gt_c = 0;
        if (manhattan_d1x != manhattan_d2x) gt_m = (manhattan_d1x < manhattan_d2x) ? 1 : 2;
        else gt_m = 0;
        if (euclidian_d1x != euclidian_d2x) gt_e = (euclidian_d1x < euclidian_d2x) ? 1 : 2;
        else gt_e = 0;


        acertos_c += (gt_c == gt_x) ? 1 : 0;
        acertos_m += (gt_m == gt_x) ? 1 : 0;
        acertos_e += (gt_e == gt_x) ? 1 : 0;

    }

    acc_c = (float) acertos_c / n * 100;
    acc_m = (float) acertos_m / n * 100;
    acc_e = (float) acertos_e / n * 100;

    printf("Acurácias: \nChebyshev: %.2f\nManhattan: %.2f\nEuclidian: %.2f\n", acc_c, acc_m, acc_e);

    if (acc_m > acc_c && acc_m > acc_e) puts("A distância Manhattan teve o melhor desempenho");
    else if (acc_e > acc_m && acc_e > acc_c) puts("A distância Euclidiana teve o melhor desempenho");
    else if (acc_c > acc_m && acc_c > acc_e) puts("A distância de Chebyshev teve o melhor desempenho");
    else puts("Houve empate de desempenho entre algumas das distâncias");

    return 0;
}
