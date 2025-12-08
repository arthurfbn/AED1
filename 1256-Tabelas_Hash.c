#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int chave;
    struct cel* prox;
} cel;

void insere(cel* tabela[], int chave, int M) {
    int i = chave % M;
    cel* novaCel = (cel*)malloc(sizeof(cel));
    novaCel->chave = chave;
    novaCel->prox = NULL;

    if (tabela[i] == NULL)
        tabela[i] = novaCel;
    else {
        cel* atual = tabela[i];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novaCel;
    }
}

void imprimirTabela(cel* tabela[], int M) {
    for (int i = 0; i < M; i++) {
        printf("%d -> ", i);
        cel* atual = tabela[i];
        while (atual) {
            printf("%d -> ", atual->chave);
            atual = atual->prox;
        }
        printf("\\\n");
    }
}

void liberarTabela(cel* tabela[], int M) {
    for (int i = 0; i < M; i++) {
        cel* atual = tabela[i];
        while (atual) {
            cel* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        tabela[i] = NULL;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int caso = 0; caso < N; caso++) {
        if (caso > 0) printf("\n");

        int M, C;
        scanf("%d %d", &M, &C);

        cel* tabela[M];
        for (int i = 0; i < M; i++) {
            tabela[i] = NULL; 
        }

        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            insere(tabela, chave, M);
        }

        imprimirTabela(tabela, M);
        liberarTabela(tabela, M);
    }

    return 0;
}
