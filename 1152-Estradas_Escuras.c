#include <stdio.h>
#include <stdlib.h>


typedef struct aresta{
    int u, v, w;
} aresta;

void trocar(aresta *a, aresta *b) {
    aresta temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(aresta arr[], int baixo, int alto) {
    int pivo = arr[alto].w;
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (arr[j].w < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quicksort(aresta arr[], int baixo, int alto) {
    if (baixo < alto) {
        int p = particionar(arr, baixo, alto);
        quicksort(arr, baixo, p - 1);
        quicksort(arr, p + 1, alto);
    }
}

int encontrar(int pai[], int x) {
    if (pai[x] != x)
        pai[x] = encontrar(pai, pai[x]);
    return pai[x];
}

void unir(int pai[], int rank[], int x, int y) {
    int raizX = encontrar(pai, x);
    int raizY = encontrar(pai, y);
    
    if (raizX != raizY) {
        if (rank[raizX] > rank[raizY])
            pai[raizY] = raizX;
        else if (rank[raizX] < rank[raizY])
            pai[raizX] = raizY;
        else {
            pai[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int main() {
    int n, m;

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        aresta arestas[m];
        int custoTotal = 0, custoMST = 0;

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
            custoTotal += arestas[i].w;
        }

        quicksort(arestas, 0, m - 1);

        int pai[n], rank[n];
        for (int i = 0; i < n; i++) {
            pai[i] = i;
            rank[i] = 0;
        }

        int arestasSelecionadas = 0;
        for (int i = 0; i < m && arestasSelecionadas < n - 1; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            int w = arestas[i].w;

            if (encontrar(pai, u) != encontrar(pai, v)) {
                unir(pai, rank, u, v);
                custoMST += w;
                arestasSelecionadas++;
            }
        }
        printf("%d\n", custoTotal - custoMST);
    }

    return 0;
}
