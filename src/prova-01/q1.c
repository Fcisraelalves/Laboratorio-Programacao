#include <stdio.h>

int main() {
    unsigned char r, g, b, b0, b1, b2, m;

    puts("Insira o valor de R: ");
    scanf("%hhu", &r);
    puts("Insira o valor de G: ");
    scanf("%hhu", &g);
    puts("Insira o valor de B: ");
    scanf("%hhu", &b);

    puts("Insira o valor de M: ");
    scanf("%hhu", &m);

    b2 = (m >> 2) & 1;
    b1 = (m >> 1) & 1;
    b0 = m & 1;

    printf("b2: %hhu\nb1: %hhu\nb0: %hhu\n", b2, b1, b0);

    r =  (r & ~1) | b2;
    g =  (g & ~1) | b1;
    b = (b & ~1) | b0;

    printf("R: %hhu\nG: %hhu\nB: %hhu\n", r, g, b);
    return 0;
}
