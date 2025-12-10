#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10005

typedef struct aresta {
    int destino;
    struct aresta *prox;
} aresta;

aresta *grafo[MAX_N];
int cor[MAX_N];
int temCiclo;

void adicionaAresta(int u, int v) {
    aresta *nova = malloc(sizeof(aresta));
    nova->destino = v;
    nova->prox = grafo[u];
    grafo[u] = nova;
}

void dfs(int u) {
    if (temCiclo) return;
    
    cor[u] = 1;
    
    aresta *adj = grafo[u];
    while (adj != NULL) {
        int v = adj->destino;
        
        if (cor[v] == 1) {
            temCiclo = 1;
            return;
        }
        
        if (cor[v] == 0) {
            dfs(v);
        }
        
        adj = adj->prox;
    }
    
    cor[u] = 2;
}

void freeGrafo(int N) {
    for (int i = 1; i <= N; i++) {
        aresta *temp = grafo[i];
        while (temp != NULL) {
            aresta *liberar = temp;
            temp = temp->prox;
            free(liberar);
        }
        grafo[i] = NULL;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        for (int i = 1; i <= N; i++) {
            grafo[i] = NULL;
            cor[i] = 0;
        }
        
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
        
        freeGrafo(N);
    }
    
    return 0;
}