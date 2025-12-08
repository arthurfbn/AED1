#include <stdio.h>
#include <stdlib.h>

//The implentation of MergeSort´s algorithm is based on the guide's book  of this disciplin 'Algoritmos em linguagem C' written by Paulo Feofiloff

int trocas;
void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p; j = q; k = 0;
    
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
            trocas += (q - i);
        }
    }

    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    
    for (i = p; i < r; i++) v[i] = w[i - p];
    
    free(w);
}

void Mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        Mergesort(p, q, v);
        Mergesort(q, r, v);
        Intercala(p, q, r, v);
    }
}

int main() {
    int n;
    
    while (scanf("%d", &n) && n != 0) {
        int arr[n], i;
        trocas = 0;
        
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        Mergesort(0, n, arr);
        
        printf("%s\n", (trocas % 2 == 0) ? "Carlos" : "Marcelo");
    }
    
    return 0;
}
