#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocar_memoria(const int tam, float **ptr);
void preencher_vetor(const int tam, float *ptr);
void printvf(const int tam, float *ptr);
void somarvf(const int tam, float *ptr, float *sum);

int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 2) {
        printf("Uso: %s <tamanho_do_vetor>\n", argv[0]);
        exit(1);
    }

    int tam = atoi(argv[1]);
    float *v = NULL;
    float sum = 0;

    alocar_memoria(tam, &v);
    preencher_vetor(tam, v);
    puts("Vetor gerado: ");
    printvf(tam, v);

    somarvf(tam, v, &sum);
    printf("Soma dos elementos: %f\n", sum);

    free(v);

    return 0;
}

void alocar_memoria(const int tam, float **ptr) {
    *ptr = malloc(tam * sizeof(float));

    if (!(*ptr)) {
        puts("Sem memória suficiente!");
        exit(2);
    }
}

void preencher_vetor(const int tam, float *ptr) {
    for (int i = 0; i<tam; i++) {
        *(ptr + i) = (float) rand() / RAND_MAX;
    }
}

void printvf(const int tam, float *ptr) {
    for (int i = 0; i<tam; i++) {
        printf("[%p] %f \n", ptr+i, *(ptr+i));
    }
    puts("");
}

void somarvf(const int tam, float *ptr, float *sum) {
    for (int i = 0; i<tam; i++) {
        *sum += *(ptr + i);
    }
}
