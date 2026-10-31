#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printv(const int tam, int *ptr);
void preencher_vetor(const int tam, const int lim, int *ptr);
void alocar_memoria(const int tam, int **ptr, unsigned char zerar);
void matriz_coocorrencia(const int tam, const int lim,  int *x, int *y, int *m);

int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 3) {
        puts("Uso: ./scm1d.e <tamanho_vetores> <limite_superior>");
        exit(2);
    }

    int tam = atoi(argv[1]);
    int lim = atoi(argv[2]);

    int *x, *y, *m = NULL;

    alocar_memoria(lim * lim, &m, 1);
    alocar_memoria(tam, &x, 0);
    alocar_memoria(tam, &y, 0);

    preencher_vetor(tam, lim, x);
    preencher_vetor(tam, lim, y);

    puts("Vetor X: ");
    printv(tam, x);
    puts("");

    puts("Vetor y: ");
    printv(tam, y);
    puts("");

    matriz_coocorrencia(tam, lim,  x, y, m);

    puts("Matriz M");
    for (int i = 0; i<lim; i++) {

        printv(lim, &m[i * lim]);
    }

    free(x);
    free(y);
    free(m);

    return 0;

}

void alocar_memoria(const int tam, int **ptr, unsigned char zerar) {

    *ptr = zerar ? calloc(tam, sizeof(int)) : malloc(tam *sizeof(int));
    if (!(*ptr)) {
        puts("Sem memória suficiente!");
        exit(1);
    }
}

void printv(const int tam, int *ptr) {
    for (int i = 0; i<tam; i++) {
        printf("%i ", *(ptr + i));
    }
    puts("");
}

void preencher_vetor(const int tam, const int lim, int *ptr) {
    for (int i = 0; i<tam; i++) {
        *(ptr + i) = rand() % lim;
    }

}

void matriz_coocorrencia(const int tam, const int lim,  int *x, int *y, int *m) {
    for (int i = 0; i<tam; i++) {
        m[*(x+i) * lim + *(y+i)] += 1;
    }
}
