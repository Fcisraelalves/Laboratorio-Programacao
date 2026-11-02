#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocar_memoria(const int tam, int **ptr, const unsigned char zerar);
void alocar_memoriaf(const int tam, double **ptr, const unsigned char zerar);
void preencher_vetor(const int tam, const int lim, int *ptr);
void printv(const int tam, int *ptr);
void printvf(const int tam, double *ptr);
void find_min_max_values(const int tam, int *ptr, int *pmax, int *pmin);
void min_max_scaler(const int tam, const int min, const int max, int *ptr, double *ptr_norm);


int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 3) {
        printf("Uso: %s <tamanho_do_vetor> <limite_de_valor>\n", argv[0]);
        exit(1);
    }

    int tam = atoi(argv[1]);
    int lim = atoi(argv[2]);
    int min, max = 0;
    int *v = NULL;
    double *v_norm = NULL;

    alocar_memoria(tam, &v, 0);
    alocar_memoriaf(tam, &v_norm, 0);
    preencher_vetor(tam, lim, v);

    puts("Vetor gerado: ");
    printv(tam, v);

    find_min_max_values(tam, v, &max, &min);
    min_max_scaler(tam, min, max, v, v_norm);

    puts("Vetor normalizado: ");
    printvf(tam, v_norm);

    free(v_norm);
    free(v);

    return 0;
}

void alocar_memoria(const int tam, int **ptr, const unsigned char zerar) {
    if (zerar) {
        *ptr = calloc(tam, sizeof(int));
    } else {
        *ptr = malloc(tam * sizeof(int));
    }

    if (!(*ptr)) {
        puts("Sem memória suficiente!");
        exit(2);
    }
}

void alocar_memoriaf(const int tam, double **ptr, const unsigned char zerar) {
    if (zerar) {
        *ptr = calloc(tam, sizeof(double));
    } else {
        *ptr = malloc(tam * sizeof(double));
    }

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

void printvf(const int tam, double *ptr) {
    for (int i = 0; i<tam; i++) {
        printf("[%p] %f \n", ptr+i, *(ptr+i));
    }
    puts("");
}

void find_min_max_values(const int tam, int *ptr, int *pmax, int *pmin) {
    for (int i = 0; i<tam; i++) {
        if (i == 0) {
            *pmax = *pmin = *ptr;
        } else {
            if (*(ptr+i) > *pmax) *pmax = *(ptr+i);
            if (*(ptr+i) < *pmin) *pmin = *(ptr+i);
        }

    }

}

void min_max_scaler(const int tam, const int min, const int max, int *ptr, double *ptr_norm) {
    for (int i = 0; i<tam; i++) {
        *(ptr_norm+i) = (double) (*(ptr + i) - min) / (max - min);
    }
}
