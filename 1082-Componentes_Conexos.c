#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grafo[26][26]; 
int visitado[26];        

void dfs(int v, int n, char *componente, int *index) {
    visitado[v] = 1; 
    componente[(*index)++] = 'a' + v; 

    for (int i = 0; i < n; i++) {
        if (grafo[v][i] && !visitado[i]) 
            dfs(i, n, componente, index);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int caso = 1; caso <= N; caso++) {
        int V, E;
        scanf("%d %d", &V, &E); 

        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));

        for (int i = 0; i < E; i++) {
            char u, v;
            scanf(" %c %c", &u, &v); 
            grafo[u - 'a'][v - 'a'] = 1;
            grafo[v - 'a'][u - 'a'] = 1; 
        }

        printf("Case #%d:\n", caso);

        int componentes = 0;

        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                char componente[26];
                int index = 0;

                dfs(i, V, componente, &index);

                for (int j = 0; j < index; j++) {
                    for (int k = j + 1; k < index; k++) {
                        if (componente[j] > componente[k]) {
                            char temp = componente[j];
                            componente[j] = componente[k];
                            componente[k] = temp;
                        }
                    }
                }

                for (int j = 0; j < index; j++) {
                    printf("%c,", componente[j]);
                }
                printf("\n");

                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}