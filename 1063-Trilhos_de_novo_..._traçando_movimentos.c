#include <stdio.h>

#define MAX 30

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        char entrada[MAX], saida[MAX];
        for (int i = 0; i < n; i++)
            scanf(" %c", &entrada[i]);
        for (int i = 0; i < n; i++)
            scanf(" %c", &saida[i]);

        char pilha[MAX];
        int topo = -1;
        int i = 0, j = 0;

        char resultado[2 * MAX];
        int k = 0;
        int possivel = 1;

        while (j < n) {
            if (topo >= 0 && pilha[topo] == saida[j]) {
                topo--;
                resultado[k++] = 'R';
                j++;
            } else if (i < n) {
                pilha[++topo] = entrada[i++];
                resultado[k++] = 'I';
            } else {
                possivel = 0;
                break;
            }
        }

        for (int x = 0; x < k; x++)
            printf("%c", resultado[x]);

        if (!possivel)
            printf(" Impossible");

        printf("\n");
    }

    return 0;
}
