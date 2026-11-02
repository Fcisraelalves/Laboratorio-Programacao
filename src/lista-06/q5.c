#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocar_memoria(const int tam, int **ptr, const unsigned char zerar);
void preencher_vetor(const int tam, const int lim, int *ptr);
void printv(const int tam, int *ptr);
void media(const int tam, int *ptr, float *media);
void mediana(const int tam, int *ptr, float *mediana);
void moda(const int tamf, int *freqv, int *moda);
int max(const int tam, int *ptr);
void freqv(const int tam, int *ptr, int *pfreq);


int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 3) {
        printf("Uso: %s <tamanho_do_vetor> <limite_de_valor>\n", argv[0]);
        exit(1);
    }

    int tam = atoi(argv[1]);
    int lim = atoi(argv[2]);
    float mediav, medianav;
    int modav, maxv;
    int *v = NULL;
    int *vfreq = NULL;

    alocar_memoria(tam, &v, 0);
    preencher_vetor(tam, lim, v);
    puts("Vetor gerado: ");
    printv(tam, v);

    maxv = max(tam, v);
    alocar_memoria(maxv+1, &vfreq, 1);
    freqv(tam, v, vfreq);
    moda(maxv+1, vfreq, &modav);
    mediana(tam, v, &medianav);
    media(tam, v, &mediav);

    puts("Estatísticas: ");
    printf("Média: %.2f\n", mediav);
    printf("Mediana: %.2f\n", medianav);
    printf("Moda: %d\n", modav);

    free(v);
    free(vfreq);

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

void media(const int tam, int *ptr, float *media) {
    int soma = 0;
    for (int i = 0; i<tam; i++) {
        soma += *(ptr + i);
    }
    *media = (float) soma / tam;
}

void mediana(const int tam, int *ptr, float *mediana) {
    int idx_meio = (int) tam/2 + 1;
    if (tam % 2) {
        *mediana = *(ptr + idx_meio);
    } else {
        *mediana = (*(ptr + idx_meio) + *(ptr + idx_meio - 1)) / 2;
    }
}

void moda(const int tamf, int *freqv, int *moda) {
    int maximo = max(tamf, freqv);
    for (int i = 0; i<tamf; i++) {
        if (maximo == *(freqv+i)) {
            *moda = i;
        }
    }
}
int max(const int tam, int *ptr) {
    int max;
    for (int i = 0; i<tam; i++) {
        if (i == 0) {
            max = *(ptr+i);
        } else {
            if (*(ptr+i) > max) {
                max = *(ptr+i);
            }
        }
    }
    return max;
}

void freqv(const int tam, int *ptr, int *pfreq) {
    for (int i = 0; i<tam; i++) {
        *(pfreq + *(ptr +i)) += 1;
    }
}
