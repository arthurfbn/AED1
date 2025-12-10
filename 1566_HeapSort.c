#include <stdio.h>
#include <stdlib.h>

const int MAXSEQ = 100;
const int MAXPOPULACAO = 3000000;

void peneira(int i, int n, int v[]) {
    int filho, t;
    filho = 2 * i + 1;
    while (filho < n) {
        if (filho + 1 < n && v[filho + 1] > v[filho])
            filho++;
        if (v[i] >= v[filho])
            break;
        t = v[i];
        v[i] = v[filho];
        v[filho] = t;
        i = filho;
        filho = 2 * i + 1;
    }
}

void heapsort(int n, int v[]) {
    int i, t;
    for (i = n / 2 - 1; i >= 0; i--)
        peneira(i, n, v);
    for (i = n - 1; i > 0; i--) {
        t = v[0];
        v[0] = v[i];
        v[i] = t;
        peneira(0, i, v);
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

        heapsort(n, v);

        for (int j = 0; j < n; j++) {
            printf("%d", v[j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");

        free(v);
    }
    return 0;
}