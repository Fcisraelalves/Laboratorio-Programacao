#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void alocar_memoria(const int tam, int **ptr, const unsigned char zerar);
void preencher_vetor(const int tam, const int lim, int *ptr);
void printv(const int tam, int *ptr);
void binarizar_matriz(const int qtd_linhas, const int qtd_colunas, const int limiar, int *ptr, int *ptr_bin);


int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 5) {
        printf("Uso: %s <qtd_de_linhas> <qtd_de_colunas> <limite_de_valor> <limiar>\n", argv[0]);
        exit(1);
    }

    int qtd_linhas = atoi(argv[1]);
    int qtd_colunas = atoi(argv[2]);
    int lim = atoi(argv[3]);
    int limiar = atoi(argv[4]);

    int *m, *m_bin = NULL;

    alocar_memoria(qtd_linhas * qtd_colunas, &m, 0);
    alocar_memoria(qtd_linhas * qtd_colunas, &m_bin, 0);
    preencher_vetor(qtd_linhas * qtd_colunas, lim, m);
    puts("Matriz gerada: ");
    for (int i = 0; i<qtd_linhas; i++) {
        printv(qtd_colunas, (m + qtd_colunas * i));
    }

    binarizar_matriz(qtd_linhas, qtd_colunas, limiar, m, m_bin);

    puts("Matriz binarizada: ");
    for (int i = 0; i<qtd_linhas; i++) {
        printv(qtd_colunas, (m_bin + qtd_colunas * i));
    }

    free(m);
    free(m_bin);

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
        printf("%i ", *(ptr+i));
    }
    puts("");
}

void binarizar_matriz(const int qtd_linhas, const int qtd_colunas, const int limiar, int *ptr, int *ptr_bin) {
    for (int i = 0; i<qtd_linhas; i++) {
        for (int k = 0; k<qtd_colunas; k++) {
            if ((*(ptr + i*qtd_colunas + k)) > limiar) {
                *(ptr_bin + i*qtd_colunas + k) = 1;
            } else {
                *(ptr_bin + i*qtd_colunas + k) = 0;
            }
        }
    }
}
