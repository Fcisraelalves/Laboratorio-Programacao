#include <stdio.h>
#define N 10
int main() {
    unsigned char pixel, p_max, p_min;
    float p_norm;

    for (int i = 0; i<N; i++) {
        printf("Insira o %iº pixel: ", i+1);
        scanf("%hhu", &pixel);

        if (i == 0) {
            p_max = p_min = pixel;
        } else {
            if (pixel > p_max) {
                p_max = pixel;
            }
            if (pixel < p_min) {
                p_min = pixel;
            }
        }
    }

    puts("Insira o pixel a ser normalizado: ");
    scanf("%hhu", &pixel);

    p_norm = (float) (pixel - p_min) / (p_max - p_min);

    printf("Pixel Normalizado: %.3f\n", p_norm);
    return 0;
}
