#include <stdio.h>
#include <stdlib.h>


int *alocar_memoria(const int t, const unsigned char zerar);
double *alocar_memoriaf(const int t, const unsigned char zerar);
int somar_vetor(const int const* v, const int t);
void printar_vetor(const int const* v, const int t);
void printar_vetorf(const double const* v, const int t);
int *hist(const int const* v, const int t, const int qtd_f);
double *prob(const int const* v, const int const* f, const int t_v, const int t_f);


int main() {

    int qtd, qtd_f, max, min;


    puts("Insira o número mínimo: ");
    scanf("%i", &min);

    puts("Insira o número máximo: ");
    scanf("%i", &max);

    qtd_f = max - min + 1;

    puts("Insira a quantidade de elementos que será lida: ");
    scanf("%i", &qtd);

    int *v = malloc(qtd * sizeof(int));
    if (v == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    for (int i = 0; i<qtd; i++) {
        printf("Insira um número: ");
        scanf("%i", (v+i));
    }

    int *f = hist(v, qtd, qtd_f);
    double *p = prob(v, f, qtd, qtd_f);

    puts("Vetor original: ");
    printar_vetor(v, qtd);
    puts("Vetor de frequências: ");
    printar_vetor(f, qtd_f);
    puts("Vetor de probabilidades: ");
    printar_vetorf(p, qtd_f);


    return 0;
}

int *alocar_memoria(const int t, const unsigned char zerar) {
    int *v = 0;

    if (zerar) {
        int *v = calloc(t, sizeof(int));
    } else {
        int *v = malloc(t * sizeof(int));
    }

    if (v == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    return v;

}

double *alocar_memoriaf(const int t, const unsigned char zerar) {
    double *v = 0;

    if (zerar) {
        double *v = calloc(t, sizeof(double));
    } else {
        double *v = malloc(t * sizeof(double));
    }

    if (v == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    return v;



}
int somar_vetor(const int const* v, const int t) {
    int total = 0;

    for (int i = 0; i<t; i++) {
        total += *(v+i);
    }

    return total;
}

void printar_vetor(const int const* v, const int t) {
    int total = 0;

    for (int i = 0; i<t; i++) {
        printf("%i ", *(v+i));
    }

    puts("");

}

void printar_vetorf(const double const* v, const int t) {
    int total = 0;

    for (int i = 0; i<t; i++) {
        printf("%lf ", *(v+i));
    }

    puts("");

}

int *hist(const int const* v, const int t, const int qtd_f) {

    int *f = calloc(qtd_f, sizeof(int));
    if (f == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }

    for (int i = 0; i<t; i++) {
        *(f+*(v + i)) += 1;
    }

    return f;
}

double *prob(const int const* v, const int const* f, const int t_v, const int t_f) {
    double *p = calloc(t_f, sizeof(double));
    if (p == 0) {
        puts("Memória insuficiente!");
        exit(1);
    }
    int total = somar_vetor(f, t_f);

    for (int i = 0; i<t_f; i++) {
        *(p+i) = (double) *(f+i) / total;
    }

    return p;
}
