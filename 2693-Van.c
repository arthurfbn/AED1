#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char *nome;   
    char regiao;     
    int preco;        
    struct cel *prox;
} cel;

void insere(char *nome, char regiao, int preco, cel **ini, cel **fim) {
    cel *novaCel = (cel*)malloc(sizeof(cel));
    novaCel->nome = (char*)malloc(51 * sizeof(char));
    strcpy(novaCel->nome, nome);
    novaCel->regiao = regiao;
    novaCel->preco = preco;
    novaCel->prox = NULL;

    if (*fim == NULL) 
        *ini = *fim = novaCel;
    else {
        (*fim)->prox = novaCel;
        *fim = novaCel;
    }
}

void bubbleSort(cel *list) {
    cel *i, *j;
    char tempNome[51];
    char tempRegiao;
    int tempPreco;

    for (i = list; i != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->preco > j->preco || 
               (i->preco == j->preco && i->regiao > j->regiao) || 
               (i->preco == j->preco && i->regiao == j->regiao && strcmp(i->nome, j->nome) > 0)) {

                strcpy(tempNome, i->nome);
                strcpy(i->nome, j->nome);
                strcpy(j->nome, tempNome);

                tempRegiao = i->regiao;
                i->regiao = j->regiao;
                j->regiao = tempRegiao;

                tempPreco = i->preco;
                i->preco = j->preco;
                j->preco = tempPreco;
            }
        }
    }
}

void printaLista(cel *c) {
    cel *atual;
    for (atual = c; atual != NULL; atual = atual->prox)
        printf("%s\n", atual->nome);
}

int main() {
    cel *ini = NULL, *fim = NULL;

    int numEntradas, preco;
    char nome[51], regiao;

    while (scanf("%d", &numEntradas) != EOF) {
        for (int i = 0; i < numEntradas; i++) {
            scanf("%s %c %d", nome, &regiao, &preco);
            insere(nome, regiao, preco, &ini, &fim);
        }

        bubbleSort(ini);
        printaLista(ini);
        ini = fim = NULL;
    }

    return 0;
}
