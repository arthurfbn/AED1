#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k;
    int vagao[1000];
    int pilha[1000];
    int topo;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            scanf("%d", &vagao[0]);
            if (vagao[0] == 0) {
                printf("\n");
                break;
            }

            for (i = 1; i < n; i++) {
                scanf("%d", &vagao[i]);
            }

            topo = -1;
            k = 0;

            for (i = 1; i <= n; i++) {
                pilha[++topo] = i;

                while (topo != -1 && pilha[topo] == vagao[k]) {
                    topo--;
                    k++;
                }
            }

            if (k == n) printf("Yes\n");
            else        printf("No\n");
        }
    }
    return 0;
}