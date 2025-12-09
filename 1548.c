#include <stdio.h>

int separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for(k = p; k < r; k++){
        if (v[k] >= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

void quicksort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = separa (p, r, v);
        quicksort (p, j - 1, v);
        quicksort (j + 1, r, v);
    }
}

int main() {
    int T, M, a[1000], b[1000], i, c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &M);
        for (i = 0; i < M; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        quicksort(0, M-1, b);
        c = 0;
        for (i = 0; i < M; i++)
            if (a[i] == b[i]) c++;
        printf("%d\n", c);
    }
    return 0;
}
