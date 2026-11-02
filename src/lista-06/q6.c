#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocar_memoria(const int tam, int **ptr, const unsigned char zerar);
void preencher_vetor(const int tam, const int lim, int *ptr);
void printv(const int tam, int *ptr);
void subv(const int tam, int *ptr1, int *ptr2,  int *result);
void produto_escalar(const int tam, int *ptr1, int *ptr2,  int *result);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Uso: %s <tamanho_do_vetor> <limite_de_valor>\n", argv[0]);
        exit(1);
    }

    int tam = atoi(argv[1]);
    int lim = atoi(argv[2]);

    int *v1, *v2, *result = NULL;
    int p_escalar = 0;
    float mse;

    alocar_memoria(tam, &v1, 0);
    alocar_memoria(tam, &v2, 0);
    alocar_memoria(tam, &result, 0);
    preencher_vetor(tam, lim, v1);
    preencher_vetor(tam, lim, v2);
    subv(tam, v1, v2, result);
    produto_escalar(tam, result, result, &p_escalar);

    mse = (float) p_escalar / tam;

    puts("Vetor 1: ");
    printv(tam, v1);

    puts("Vetor 2: ");
    printv(tam, v2);


    printf("MSE: %.4f\n", mse);

    free(v1);
    free(v2);
    free(result);

    return 0;

}

void alocar_memoria(const int tam, int **ptr, const unsigned char zerar) {
    *ptr = zerar ? calloc(tam, sizeof(int)) : malloc(tam * sizeof(int));

    if (!(*ptr)) {
        puts("Sem memória suficiente!");
        exit(2);
    }
}

void preencher_vetor(const int tam, const int lim, int *ptr) {
    for (int i = 0; i<tam; i++) {
        *(ptr + i) = rand() % lim;
    }
}

void printv(const int tam, int *ptr) {
    for (int i = 0; i<tam; i++) {
        printf("[%p] %i \n", ptr+i, *(ptr+i));
    }
    puts("");
}

void subv(const int tam, int *ptr1, int *ptr2,  int *result) {
    for (int i = 0; i<tam; i++) {
        *(result + i) = *(ptr1 + i) - *(ptr2 + i);
    }
}

void produto_escalar(const int tam, int *ptr1, int *ptr2,  int *result) {
    for (int i = 0; i<tam; i++) {
        *result += *(ptr1 + i) * *(ptr2 + i);
    }
}
