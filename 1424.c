#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000000

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) == 2) {
        int **pos = calloc(MAXV + 1, sizeof(int *));
        int *cont = calloc(MAXV + 1, sizeof(int));

        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);

            cont[x]++;
            pos[x] = realloc(pos[x], cont[x] * sizeof(int));
            pos[x][cont[x] - 1] = i;
        }

        while (m--) {
            int k, v;
            scanf("%d %d", &k, &v);

            if (cont[v] >= k)
                printf("%d\n", pos[v][k - 1]);
            else
                printf("0\n");
        }

        for (int i = 1; i <= MAXV; i++)
            free(pos[i]);

        free(pos);
        free(cont);
    }

    return 0;
}
