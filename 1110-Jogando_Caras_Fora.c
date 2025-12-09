#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct cel {
    int valor;
} cel;

cel fila[MAX];
int inicio = 0, fim = 0;

void enfileirar(int valor) {
    fila[fim].valor = valor;
    fim++;
}

int desenfileirar() {
    return fila[inicio++].valor;
}

int tamanho() {
    return fim - inicio;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        inicio = 0;
        fim = 0;

        for (int i = 1; i <= n; i++)
            enfileirar(i);

        printf("Discarded cards:");

        int first = 1;

        while (tamanho() > 1) {
            int d = desenfileirar();

            if (first) {
                printf(" %d", d);
                first = 0;
            } else {
                printf(", %d", d);
            }

            int m = desenfileirar();
            enfileirar(m);
        }

        int last = desenfileirar();
        printf("\nRemaining card: %d\n", last);
    }

    return 0;
}
