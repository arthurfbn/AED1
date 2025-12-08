#include <stdio.h>
#include <stdlib.h>

//The implentation of MergeSort´s algorithm is based on the guide's book  of this disciplin 'Algoritmos em linguagem C' written by Paulo Feofiloff

void Intercala(int p, int q, int r, int v[], int m) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    if (w == NULL) exit(1);

    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {
        int a = v[i], b = v[j];
        int modA = a % m, modB = b % m;
        int a_impar = (a % 2 != 0), b_impar = (b % 2 != 0);

        if (modA < modB)
            w[k++] = v[i++];
        else if (modA > modB)
            w[k++] = v[j++];
        else {
            if (a_impar && !b_impar)
                w[k++] = v[i++];
            else if (!a_impar && b_impar)
                w[k++] = v[j++];
            else if (a_impar && b_impar) {
                if (a > b)
                    w[k++] = v[i++];
                else
                    w[k++] = v[j++];
            } else {
                if (a < b)
                    w[k++] = v[i++];
                else
                    w[k++] = v[j++];
            }
        }
    }

    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];

    for (i = p; i < r; i++) 
        v[i] = w[i - p];
    
    free(w);
}

void Mergesort(int p, int r, int v[], int m) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v, m);
        Mergesort(q, r, v, m);
        Intercala(p, q, r, v, m);
    }
}

int main() {
    int n, m;

    while (1) {
        scanf("%d %d", &n, &m);
        
        if (n == 0 && m == 0) break;

        int v[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        Mergesort(0, n, v, m);

        printf("%d %d\n", n, m);

        for (int i = 0; i < n; i++) {
            printf("%d\n", v[i]);
        }
    }

    printf("0 0\n");

    return 0;
}