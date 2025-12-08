#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char lingua[21];
    char traducao[101];
} Traducao;

typedef struct {
    char nome[101];
    char lingua[21];
} Crianca;

int main() {
    int N, M;
    
    scanf("%d", &N);
    getchar();
    
    Traducao *traducoes = (Traducao *)malloc(N * sizeof(Traducao));
    
    for (int i = 0; i < N; i++) {
        fgets(traducoes[i].lingua, 21, stdin);
        traducoes[i].lingua[strcspn(traducoes[i].lingua, "\n")] = 0;

        fgets(traducoes[i].traducao, 101, stdin);
        traducoes[i].traducao[strcspn(traducoes[i].traducao, "\n")] = 0;
    }

    scanf("%d", &M);
    getchar();

    Crianca *criancas = (Crianca *)malloc(M * sizeof(Crianca));
    
    for (int i = 0; i < M; i++) {
        fgets(criancas[i].nome, 101, stdin);
        criancas[i].nome[strcspn(criancas[i].nome, "\n")] = 0; 

        fgets(criancas[i].lingua, 21, stdin);
        criancas[i].lingua[strcspn(criancas[i].lingua, "\n")] = 0;
    }

    for (int i = 0; i < M; i++) {
        printf("%s\n", criancas[i].nome);
        for (int j = 0; j < N; j++) {
            if (strcmp(criancas[i].lingua, traducoes[j].lingua) == 0) {
                printf("%s\n", traducoes[j].traducao);
                break;
            }
        }
        printf("\n");
    }
    free(traducoes);
    free(criancas);

    return 0;
}
