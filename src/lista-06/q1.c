#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocar_memoria(const int tam, int **ptr);
void preencher_vetor(const int tam, const int lim, int *ptr);
void printv(const int tam, int *ptr);


int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 3) {
        printf("Uso: %s <tamanho_do_vetor> <limite_de_valor>\n", argv[0]);
        exit(1);
    }

    int tam = atoi(argv[1]);
    int lim = atoi(argv[2]);
    int *ppar = NULL;
    int *v = NULL;

    alocar_memoria(tam, &v);
    preencher_vetor(tam, lim, v);
    puts("Vetor gerado: ");
    printv(tam, v);

    for (int i = 0; i<tam; i++) {
        if (!(*(v+i) % 2)) {
            ppar = v+i;
            break;
        }
    }

    printf("Endereço de memória do primeiro número par: %p\n", ppar);
    printf("Valor do primeiro número par: %d\n", *ppar);

    free(v);
    free(ppar);

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
