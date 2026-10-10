#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 40
#define COLUNAS 40
#define FINAL 9

int main() {
    srand(time(NULL));
    int valor, qtd_apareceu;
    int *pmatriz = malloc(LINHAS * COLUNAS * sizeof(int));

    qtd_apareceu = 0;
    if (pmatriz == NULL) {
        puts("Sem memória suficiente!");
        exit(1);
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            pmatriz[i * COLUNAS + j] = rand() % (FINAL + 1);
        }
    }

    printf("Insira um valor inteiro entre 0 e %i: ", FINAL);
    scanf("%i", &valor);


    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (pmatriz[i * COLUNAS + j] == valor) {
                qtd_apareceu++;
            }
            printf("%i ", pmatriz[i * COLUNAS + j]);
        }
        puts("");
    }

    printf("O valor %i apareceu %i vezes na matriz.", valor, qtd_apareceu);
    free(pmatriz);
    
    return 0;
}
