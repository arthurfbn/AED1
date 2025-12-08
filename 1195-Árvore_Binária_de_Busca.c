#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int data;
    struct cel* esq;
    struct cel* dir;
} cel;

cel* criaCel(int data) {
    cel* novaCel = (cel*)malloc(sizeof(cel));
    novaCel->data = data;
    novaCel->esq = NULL;
    novaCel->dir = NULL;
    return novaCel;
}

cel* insere(cel* raiz, int data) {
    if (raiz == NULL)  return criaCel(data);
    
    if (data < raiz->data)      raiz->esq = insere(raiz->esq, data);
    else if (data > raiz->data) raiz->dir = insere(raiz->dir, data);
    
    return raiz;
}

void preOrdenar(cel* raiz) {
    if (raiz != NULL) {
        printf(" %d", raiz->data);
        preOrdenar(raiz->esq);
        preOrdenar(raiz->dir);
    }
}

void inOrdenar(cel* raiz) {
    if (raiz != NULL) {
        inOrdenar(raiz->esq);
        printf(" %d", raiz->data);
        inOrdenar(raiz->dir);
    }
}


void posOrdenar(cel* raiz) {
    if (raiz != NULL) {
        posOrdenar(raiz->esq);
        posOrdenar(raiz->dir);
        printf(" %d", raiz->data);
    }
}

int main() {
    int c, n, valor;
    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);
        cel* root = NULL;

        for (int j = 0; j < n; j++) {
            scanf("%d", &valor);
            root = insere(root, valor);
        }

        printf("Case %d:\n", i);
        printf("Pre.:");
        preOrdenar(root);
        printf("\n");

        printf("In..:");
        inOrdenar(root);
        printf("\n");

        printf("Post:");
        posOrdenar(root);
        printf("\n\n");
    }

    return 0;
}