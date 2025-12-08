#include <stdio.h>
#include <stdlib.h>

typedef struct aresta {
    int u, v, peso;
} aresta;

aresta arestas[100000];
int pai[2000];   

void quicksort(aresta *arestas, int baixo, int alto) {
    if (baixo < alto) {
        int pivo = separa(arestas, baixo, alto);
        quicksort(arestas, baixo, pivo - 1);
        quicksort(arestas, pivo + 1, alto);
    }
}

int separa(aresta *arestas, int baixo, int alto) {
    aresta pivo = arestas[alto];
    int i = baixo - 1;
    for (int j = baixo; j < alto; j++) {
        if (arestas[j].peso < pivo.peso) {
            i++;
            aresta temp = arestas[i];
            arestas[i] = arestas[j];
            arestas[j] = temp;
        }
    }
    aresta temp = arestas[i + 1];
    arestas[i + 1] = arestas[alto];
    arestas[alto] = temp;
    return i + 1;
}

int encontrar(int u) {
    if (pai[u] == u) return u;
    return pai[u] = encontrar(pai[u]); 
}

void unir(int u, int v) {
    int raizU = encontrar(u);
    int raizV = encontrar(v);
    pai[raizV] = raizU; 
}

int kruskal(int n, int m) {
    quicksort(arestas, 0, m - 1);

    for (int i = 0; i < n; i++) {
        pai[i] = i;
    }

    int custo_total = 0;
    int arestas_adicionadas = 0;

    for (int i = 0; i < m; i++) {
        int u = arestas[i].u;
        int v = arestas[i].v;
        int peso = arestas[i].peso;
        if (encontrar(u) != encontrar(v)) {
            unir(u, v);
            custo_total += peso;
            arestas_adicionadas++;

            if (arestas_adicionadas == n - 1) break;
        }
    }

    return custo_total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        arestas[i].u--; 
        arestas[i].v--; 
    }

    int custo_total = kruskal(n, m);

    printf("%d\n", custo_total);

    return 0;
}
