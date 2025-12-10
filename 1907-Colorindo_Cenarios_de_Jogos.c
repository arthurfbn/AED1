#include <stdio.h>

#define MAX 1025

char mapa[MAX][MAX];
int visitado[MAX][MAX];
int N, M;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

typedef struct {
    int x, y;
} Pos;

Pos pilha[MAX * MAX];
int topo;

void push(int x, int y) {
    pilha[topo].x = x;
    pilha[topo].y = y;
    topo++;
}

Pos pop() {
    topo--;
    return pilha[topo];
}

void dfs(int x, int y) {
    topo = 0;
    push(x, y);
    visitado[x][y] = 1;
    
    while (topo > 0) {
        Pos atual = pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                mapa[nx][ny] == '.' && !visitado[nx][ny]) {
                visitado[nx][ny] = 1;
                push(nx, ny);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", mapa[i]);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visitado[i][j] = 0;
        }
    }
    
    int cliques = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mapa[i][j] == '.' && !visitado[i][j]) {
                dfs(i, j);
                cliques++;
            }
        }
    }
    
    printf("%d\n", cliques);
    
    return 0;
}