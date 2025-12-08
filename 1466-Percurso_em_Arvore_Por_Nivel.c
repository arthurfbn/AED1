#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The implentation of queue's algorithm is based on the guide's book  of this disciplin 'Algoritmos em linguagem C' written by Paulo Feofiloff

typedef struct no {
    int valor;
    struct no *esq, *dir;
} no;


typedef struct cel {
    no *valor;          
    struct cel *seg;   
} cel;

void Insere(cel **s, cel **t, no *y) {
    cel *nova = malloc(sizeof(cel));
    if (nova == NULL) exit(1);

    nova->valor = y;
    nova->seg = NULL;

    if (*t == NULL)
        *s = *t = nova;
    else {
        (*t)->seg = nova;
        *t = nova;
    }
}

no* Remove(cel **s, cel **t) {
    if (*s == NULL) exit(1);

    cel *p = *s;
    no *valor = p->valor;
    *s = p->seg;

    if (*s == NULL) *t = NULL;

    free(p);
    return valor;
}

no* novoNo(int valor) {
    no *no = malloc(sizeof(no));
    if (no == NULL) exit(1);
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

// Função para insere um valor na árvore binária
no* insere(no *raiz, int valor) {
    if (raiz == NULL) return novoNo(valor);

    if (valor < raiz->valor) raiz->esq = insere(raiz->esq, valor);
    else                     raiz->dir = insere(raiz->dir, valor);
    return raiz;
}

void bfs(no *raiz) {
    if (raiz == NULL) return;

    cel *s = NULL, *t = NULL;
    Insere(&s, &t, raiz);

    int first = 1;
    while (s != NULL) {
        no *current = Remove(&s, &t);

        if (!first) printf(" ");

        printf("%d", current->valor);
        first = 0;

        if (current->esq != NULL) Insere(&s, &t, current->esq);
        if (current->dir != NULL) Insere(&s, &t, current->dir);
    }
    printf("\n");
}

int main() {
    int cases;
    scanf("%d", &cases);

    for (int c = 1; c <= cases; c++) {
        int n, value;
        scanf("%d", &n);

        no *raiz = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            raiz = insere(raiz, value);
        }

        printf("Case %d:\n", c);
        bfs(raiz);
        printf("\n");
    }

    return 0;
}
