#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int grafo[MAX_VERTICES][MAX_VERTICES];
int custo_minimo[MAX_VERTICES];        
int incluido[MAX_VERTICES];            

int encontrar_vertice_minimo(int n) {
    int minimo = INF;
    int indice_minimo = -1;

    for (int v = 0; v < n; v++) {
        if (!incluido[v] && custo_minimo[v] < minimo) {
            minimo = custo_minimo[v];
            indice_minimo = v;
        }
    }

    return indice_minimo;
}

int prim(int n) {
    for (int i = 0; i < n; i++) {
        custo_minimo[i] = INF;
        incluido[i] = 0;
    }

    custo_minimo[0] = 0;
    int custo_total = 0;

    for (int i = 0; i < n; i++) {
        int u = encontrar_vertice_minimo(n); 
        incluido[u] = 1;                    
        custo_total += custo_minimo[u];    

        for (int v = 0; v < n; v++) {
            if (grafo[u][v] && !incluido[v] && grafo[u][v] < custo_minimo[v]) {
                custo_minimo[v] = grafo[u][v];
            }
        }
    }

    return custo_total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grafo[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, custo;
        scanf("%d %d %d", &u, &v, &custo);
        u--;
        v--; 
        grafo[u][v] = custo;
        grafo[v][u] = custo;
    }

    int custo_total = prim(n);
    printf("%d\n", custo_total);

    return 0;
}