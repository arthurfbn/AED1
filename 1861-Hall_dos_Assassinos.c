#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoAssassino {
    char nome[15];
    int mortes;
    struct NoAssassino *esq, *dir;
} NoAssassino;

typedef struct NoMorto {
    char nome[15];
    struct NoMorto *esq, *dir;
} NoMorto;

NoAssassino* insereAssassino(NoAssassino *raiz, char *nome) {
    if (raiz == NULL) {
        NoAssassino *novo = malloc(sizeof(NoAssassino));
        strcpy(novo->nome, nome);
        novo->mortes = 1;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    
    int cmp = strcmp(nome, raiz->nome);
    if (cmp < 0) {
        raiz->esq = insereAssassino(raiz->esq, nome);
    } else if (cmp > 0) {
        raiz->dir = insereAssassino(raiz->dir, nome);
    } else {
        raiz->mortes++;
    }
    return raiz;
}

NoMorto* insereMorto(NoMorto *raiz, char *nome) {
    if (raiz == NULL) {
        NoMorto *novo = malloc(sizeof(NoMorto));
        strcpy(novo->nome, nome);
        novo->esq = novo->dir = NULL;
        return novo;
    }
    
    int cmp = strcmp(nome, raiz->nome);
    if (cmp < 0) {
        raiz->esq = insereMorto(raiz->esq, nome);
    } else if (cmp > 0) {
        raiz->dir = insereMorto(raiz->dir, nome);
    }
    return raiz;
}

int buscaMorto(NoMorto *raiz, char *nome) {
    if (raiz == NULL) return 0;
    
    int cmp = strcmp(nome, raiz->nome);
    if (cmp < 0) return buscaMorto(raiz->esq, nome);
    if (cmp > 0) return buscaMorto(raiz->dir, nome);
    return 1;
}

void imprimeAssassinos(NoAssassino *raiz, NoMorto *mortos) {
    if (raiz == NULL) return;
    
    imprimeAssassinos(raiz->esq, mortos);
    
    if (!buscaMorto(mortos, raiz->nome)) {
        printf("%s %d\n", raiz->nome, raiz->mortes);
    }
    
    imprimeAssassinos(raiz->dir, mortos);
}

void liberaAssassinos(NoAssassino *raiz) {
    if (raiz == NULL) return;
    liberaAssassinos(raiz->esq);
    liberaAssassinos(raiz->dir);
    free(raiz);
}

void liberaMortos(NoMorto *raiz) {
    if (raiz == NULL) return;
    liberaMortos(raiz->esq);
    liberaMortos(raiz->dir);
    free(raiz);
}

int main() {
    NoAssassino *assassinos = NULL;
    NoMorto *mortos = NULL;
    char assassino[15], vitima[15];
    
    while (scanf("%s %s", assassino, vitima) != EOF) {
        assassinos = insereAssassino(assassinos, assassino);
        mortos = insereMorto(mortos, vitima);
    }
    
    printf("HALL OF MURDERERS\n");
    imprimeAssassinos(assassinos, mortos);
    
    liberaAssassinos(assassinos);
    liberaMortos(mortos);
    
    return 0;
}