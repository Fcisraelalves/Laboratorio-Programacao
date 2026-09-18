#include <stdio.h>
#define N 10
int main() {

    int x_anterior_2, x_anterior_1, x;
    float y;
    for (int i = 0; i<N; i++) {
        printf("Insira o %iº valor para x: ", i+1);
        scanf("%i", &x);
        if (i == 0) {
            x_anterior_2 = x;
        } else if (i == 1) {
            x_anterior_1 = x;
        }
        else {
            y = (float) (x_anterior_2 + x_anterior_1 + x) / 3;
            printf("y_{%i}: %.2f\n", i-2, y);
            x_anterior_2 = x_anterior_1;
            x_anterior_1 = x;
        }
    }
    return 0;
}
