#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_C 10005
#define MAX_HEAP 500005
#define INF INT_MAX

typedef struct aresta {
    int destino;
    int custo;
    struct aresta *prox;
} aresta;

typedef struct {
    int cidade;
    int custo;
    int paridade;
} Estado;

aresta *grafo[MAX_C];
int dist[MAX_C][2];

Estado heap[MAX_HEAP];
int tamanhoHeap;

void trocar(int i, int j) {
    Estado temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void insereHeap(Estado e) {
    heap[tamanhoHeap] = e;
    int i = tamanhoHeap;
    tamanhoHeap++;
    
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (heap[i].custo < heap[pai].custo) {
            trocar(i, pai);
            i = pai;
        } else break;
    }
}

Estado removeHeap() {
    Estado min = heap[0];
    tamanhoHeap--;
    heap[0] = heap[tamanhoHeap];
    
    int i = 0;
    while (1) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        int menor = i;
        
        if (esq < tamanhoHeap && heap[esq].custo < heap[menor].custo)
            menor = esq;
        if (dir < tamanhoHeap && heap[dir].custo < heap[menor].custo)
            menor = dir;
        
        if (menor != i) {
            trocar(i, menor);
            i = menor;
        } else break;
    }
    
    return min;
}

void adicionaAresta(int u, int v, int custo) {
    aresta *nova = malloc(sizeof(aresta));
    nova->destino = v;
    nova->custo = custo;
    nova->prox = grafo[u];
    grafo[u] = nova;
    
    nova = malloc(sizeof(aresta));
    nova->destino = u;
    nova->custo = custo;
    nova->prox = grafo[v];
    grafo[v] = nova;
}

int dijkstra(int C) {
    tamanhoHeap = 0;
    
    for (int i = 1; i <= C; i++) {
        dist[i][0] = dist[i][1] = INF;
    }
    
    dist[1][0] = 0;
    Estado inicial = {1, 0, 0};
    insereHeap(inicial);
    
    while (tamanhoHeap > 0) {
        Estado atual = removeHeap();
        
        if (atual.custo > dist[atual.cidade][atual.paridade]) continue;
        
        if (atual.cidade == C && atual.paridade == 0) {
            return atual.custo;
        }
        
        aresta *adj = grafo[atual.cidade];
        while (adj != NULL) {
            int novaParidade = 1 - atual.paridade;
            int novoCusto = atual.custo + adj->custo;
            
            if (novoCusto < dist[adj->destino][novaParidade]) {
                dist[adj->destino][novaParidade] = novoCusto;
                Estado novo = {adj->destino, novoCusto, novaParidade};
                insereHeap(novo);
            }
            
            adj = adj->prox;
        }
    }
    
    return -1;
}

void freeGrafo(int C) {
    for (int i = 1; i <= C; i++) {
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
    int C, V;
    
    while (scanf("%d %d", &C, &V) != EOF) {
        for (int i = 1; i <= C; i++) {
            grafo[i] = NULL;
        }
        
        for (int i = 0; i < V; i++) {
            int c1, c2, g;
            scanf("%d %d %d", &c1, &c2, &g);
            adicionaAresta(c1, c2, g);
        }
        
        int resultado = dijkstra(C);
        printf("%d\n", resultado);
        
        freeGrafo(C);
    }
    
    return 0;
}