#include <stdio.h>
#include <stdlib.h>

const int MAXSEQ = 100;
const int MAXPOPULACAO = 3000000;

void intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i - p];
    free(w);
}

void mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main() {
    int nc = 0;
    int n = 0;
    int *v;

    scanf("%d", &nc);

    if (nc > MAXSEQ)
        return 1;

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        if (n > MAXPOPULACAO)
            return 1;

        v = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[j]);
            if (v[j] < 20 || v[j] > 230)
                return 1;
        }

        mergesort(0, n, v);

        for (int j = 0; j < n; j++) {
            printf("%d", v[j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");

        free(v);
    }
    return 0;
}