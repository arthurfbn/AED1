#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int x, menor, pos;
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (i == 0 || x < menor) {
            menor = x;
            pos = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);

    return 0;
}