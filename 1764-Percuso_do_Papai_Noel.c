#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50005

typedef struct {
    int u, v, peso;
} Aresta;

int pai[MAX_N];
int rank[MAX_N];
Aresta arestas[MAX_N];

int separa(int p, int r) {
    Aresta c, t;
    int j, k;
    c = arestas[r];
    j = p;
    for (k = p; k < r; k++) {
        if (arestas[k].peso <= c.peso) {
            t = arestas[j];
            arestas[j] = arestas[k];
            arestas[k] = t;
            j++;
        }
    }
    arestas[r] = arestas[j];
    arestas[j] = c;
    return j;
}

void quicksort(int p, int r) {
    int j;
    if (p < r) {
        j = separa(p, r);
        quicksort(p, j - 1);
        quicksort(j + 1, r);
    }
}

int encontrar(int x) {
    if (pai[x] != x) {
        pai[x] = encontrar(pai[x]);
    }
    return pai[x];
}

void unir(int x, int y) {
    int raizX = encontrar(x);
    int raizY = encontrar(y);
    
    if (raizX == raizY) return;
    
    if (rank[raizX] < rank[raizY]) {
        pai[raizX] = raizY;
    } else if (rank[raizX] > rank[raizY]) {
        pai[raizY] = raizX;
    } else {
        pai[raizY] = raizX;
        rank[raizX]++;
    }
}

int main() {
    int M, N;
    
    while (scanf("%d %d", &M, &N) && (M || N)) {
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }
        
        quicksort(0, N - 1);
        
        for (int i = 0; i < M; i++) {
            pai[i] = i;
            rank[i] = 0;
        }
        
        long long custoTotal = 0;
        int arestasUsadas = 0;
        
        for (int i = 0; i < N && arestasUsadas < M - 1; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            
            if (encontrar(u) != encontrar(v)) {
                unir(u, v);
                custoTotal += arestas[i].peso;
                arestasUsadas++;
            }
        }
        
        printf("%lld\n", custoTotal);
    }
    
    return 0;
}