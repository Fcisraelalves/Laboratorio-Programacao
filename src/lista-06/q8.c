#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void alocar_memoria(const int tam, int **ptr, const unsigned char zerar);
void preencher_vetor(const int tam, const int lim, int *ptr);
void printv(const int tam, int *ptr);
void somar_diagonal_principal(const int qtd_linhas, const int qtd_colunas, int *ptr, int *result);


int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc != 4) {
        printf("Uso: %s <qtd_de_linhas> <qtd_de_colunas> <limite_de_valor>\n", argv[0]);
        exit(1);
    }


    int qtd_linhas = atoi(argv[1]);
    int qtd_colunas = atoi(argv[2]);
    int lim = atoi(argv[3]);

    if (qtd_linhas != qtd_colunas) {
        puts("A matriz precisa ser uma matriz quadrada.");
        exit(3);
    }

    int *m = NULL;
    int soma = 0;

    alocar_memoria(qtd_linhas * qtd_colunas, &m, 0);
    preencher_vetor(qtd_linhas * qtd_colunas, lim, m);
    puts("Matriz gerada: ");
    for (int i = 0; i<qtd_linhas; i++) {
        printv(qtd_colunas, (m + qtd_colunas * i));
    }


    somar_diagonal_principal(qtd_linhas, qtd_colunas, m, &soma);

    printf("Soma da diagonal principal: %i\n", soma);
    (soma%2) ? puts("A soma da diagonal principal é ímpar!") : puts("A soma da diagonal principal é par!");

    free(m);
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

void somar_diagonal_principal(const int qtd_linhas, const int qtd_colunas, int *ptr, int *result) {
    for (int i = 0; i<qtd_linhas; i++) {
        for (int k = 0; k<qtd_colunas; k++) {
            if (k==i) {
                *result += *(ptr + i*qtd_colunas + k);
            }
        }
    }
}
