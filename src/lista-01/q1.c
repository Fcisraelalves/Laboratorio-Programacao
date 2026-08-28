#include <stdio.h>

int main() {

    int decimal;
    puts("Insira o valor decimal: ");
    scanf("%i", &decimal);

    printf("Hexadecimal: %X\n", decimal);
    printf("Octal: %o\n", decimal);
    return 0;
}
