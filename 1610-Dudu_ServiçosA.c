#include <stdio.h>
#include <stdlib.h>

int **grafo;
int *cor;
int temCiclo;
int N;

int** criaMatriz(int n) {
    int **matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = calloc(n, sizeof(int));
    }
    return matriz;
}

void freeMatriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void adicionaAresta(int u, int v) {
    grafo[u][v] = 1;
}

void dfs(int u) {
    if (temCiclo) return;
    
    cor[u] = 1;
    
    for (int v = 1; v <= N; v++) {
        if (grafo[u][v] == 1) {
            if (cor[v] == 1) {
                temCiclo = 1;
                return;
            }
            
            if (cor[v] == 0) {
                dfs(v);
            }
        }
    }
    
    cor[u] = 2;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int M;
        scanf("%d %d", &N, &M);
        
        grafo = criaMatriz(N + 1);
        cor = calloc(N + 1, sizeof(int));
        
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionaAresta(A, B);
        }
        
        temCiclo = 0;
        
        for (int i = 1; i <= N && !temCiclo; i++) {
            if (cor[i] == 0) {
                dfs(i);
            }
        }
        
        if (temCiclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        freeMatriz(grafo, N + 1);
        free(cor);
    }
    
    return 0;
}