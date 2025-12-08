#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX / 2 

int grafo[500][500];
int distancia[500];           
int visitado[500];           

void inicializar(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grafo[i][j] = INF; 
        }
        grafo[i][i] = 0;
    }
}


void dijkstra(int inicio, int n) {
   
    for (int i = 0; i < n; i++) {
        distancia[i] = INF;
        visitado[i] = 0;
    }
    distancia[inicio] = 0; 

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u])) 
                u = j;
        }

        visitado[u] = 1;

        for (int v = 0; v < n; v++) {
            if (grafo[u][v] != INF && distancia[u] + grafo[u][v] < distancia[v]) 
                distancia[v] = distancia[u] + grafo[u][v];
        }
    }
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m), n || m) {
        inicializar(n);

        for (int i = 0; i < m; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            x--; 
            y--; 

            if (grafo[y][x] != INF) {
                grafo[x][y] = 0;
                grafo[y][x] = 0;

            } else grafo[x][y] = h;
        }

        int k;
        scanf("%d", &k); 

        for (int i = 0; i < k; i++) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);
            origem--;  
            destino--; 

            dijkstra(origem, n);

            if (distancia[destino] == INF) 
                printf("Nao e possivel entregar a carta\n");
            else 
                printf("%d\n", distancia[destino]);
        }

        printf("\n");
    }

    return 0;
}