#include <stdio.h>
#include <limits.h>

#define INF (INT_MAX / 2)

int grafo[250][250];
int distancia[250];
int visitado[250];

void dijkstra(int inicio, int n) {
    for (int i = 0; i < n; i++) {
        distancia[i] = INF;
        visitado[i] = 0;
    }
    distancia[inicio] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u]))
                u = j;
        visitado[u] = 1;
        for (int v = 0; v < n; v++)
            if (grafo[u][v] != INF && distancia[u] + grafo[u][v] < distancia[v])
                distancia[v] = distancia[u] + grafo[u][v];
    }
}

int main() {
    int N, M, C, K;
    while (scanf("%d %d %d %d", &N, &M, &C, &K), N || M || C || K) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                grafo[i][j] = INF;
            grafo[i][i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            if (u < C && v < C) {
                if (u + 1 == v) grafo[u][v] = p;
                else if (v + 1 == u) grafo[v][u] = p;
            } 
            else if (u < C && v >= C) grafo[v][u] = p;
            else if (v < C && u >= C) grafo[u][v] = p;
            else {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        dijkstra(K, N);
        printf("%d\n", distancia[C - 1]);
    }
    return 0;
}
