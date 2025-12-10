#include <stdio.h>
#include <stdlib.h>

#define MAX_V 50

typedef struct celula {
    int vertice;
    struct celula *prox;
} celula;

typedef struct {
    celula *lista[MAX_V];
    int visitado[MAX_V];
} Grafo;

void inicializaGrafo(Grafo *g) {
    for (int i = 0; i < MAX_V; i++) {
        g->lista[i] = NULL;
        g->visitado[i] = 0;
    }
}

void adicionaAresta(Grafo *g, int u, int v) {
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) exit(1);
    nova->vertice = v;
    nova->prox = g->lista[u];
    g->lista[u] = nova;
    
    nova = malloc(sizeof(celula));
    if (nova == NULL) exit(1);
    nova->vertice = u;
    nova->prox = g->lista[v];
    g->lista[v] = nova;
}

int dfs(Grafo *g, int no) {
    g->visitado[no] = 1;
    int contador = 1;
    
    celula *temp = g->lista[no];
    while (temp != NULL) {
        if (!g->visitado[temp->vertice]) {
            contador += dfs(g, temp->vertice);
        }
        temp = temp->prox;
    }
    
    return contador;
}

void freeGrafo(Grafo *g) {
    for (int i = 0; i < MAX_V; i++) {
        celula *temp = g->lista[i];
        while (temp != NULL) {
            celula *liberar = temp;
            temp = temp->prox;
            free(liberar);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, V, A;
        Grafo g;
        
        scanf("%d", &N);
        scanf("%d %d", &V, &A);
        
        inicializaGrafo(&g);
        
        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adicionaAresta(&g, u, v);
        }
        
        int alcancaveis = dfs(&g, N);
        int movimentos = 2 * A;
        
        printf("%d\n", movimentos);
        
        freeGrafo(&g);
    }
    
    return 0;
}