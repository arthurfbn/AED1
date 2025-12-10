#include <stdio.h>
#include <stdlib.h>

const int MAXSEQ = 100;
const int MAXPOPULACAO = 3000000;

int separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r];
    j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void quicksort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = separa(p, r, v);
        quicksort(p, j - 1, v);
        quicksort(j + 1, r, v);
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

        quicksort(0, n - 1, v);

        for (int j = 0; j < n; j++) {
            printf("%d ", v[j]);
        }
        printf("\n");

        free(v);
    }
    return 0;
}
