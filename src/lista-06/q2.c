#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocar_memoria(const int tam, int **ptr);
void preencher_vetor(const int tam, const int lim, int *ptr);
void printv(const int tam, int *ptr);
void armazenar_pares(const int tam, int *ptr, int **pares);


int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 3) {
        printf("Uso: %s <tamanho_do_vetor> <limite_de_valor>\n", argv[0]);
        exit(1);
    }

    int tam = atoi(argv[1]);
    int lim = atoi(argv[2]);
    int *pares[2] = {0};
    int *v = NULL;


    alocar_memoria(tam, &v);
    preencher_vetor(tam, lim, v);
    puts("Vetor gerado: ");
    printv(tam, v);

    armazenar_pares(tam, v, pares);


    printf("Endereço de memória do primeiro número par: %p\n", *pares);
    printf("Valor do primeiro número par: %d\n\n", *(*pares));
    printf("Endereço de memória do último número par: %p\n", *(pares+1));
    printf("Valor do último número par: %d\n", *(*(pares+1)));


    free(v);

    return 0;
}

void alocar_memoria(const int tam, int **ptr) {
    *ptr = malloc(tam * sizeof(int));

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

void armazenar_pares(const int tam, int *ptr, int **pares) {

    for (int i = 0; i<tam; i++) {
        if (!(*(ptr+i) % 2)) {
            *pares = ptr+i;
            break;
        }
    }

    for (int i = tam-1; i>=0; i--) {
        if (!(*(ptr + i) % 2)) {
            *(pares+1) = ptr+i;
            break;
        }
    }
}
