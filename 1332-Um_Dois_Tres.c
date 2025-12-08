#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 10;

typedef struct cel {
    char *texto;
    int numero;
    struct cel *nova;
} cel;

void insere(char *texto, int v, cel **es, cel **et) {
    cel *novaCel;
    novaCel = (cel*)malloc(sizeof(cel));
    novaCel->numero = v;
    novaCel->texto = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(novaCel->texto, texto);
    novaCel->nova = NULL;
    if (*et == NULL) *et = *es = novaCel;
    else {
        (*et)->nova = novaCel;
        *et = novaCel;
    }
}

void printaResultados(cel *prim) {
    cel *p;
    for (p = prim; p != NULL; p = p->nova)
        if (p->numero != 0) printf("%d\n", p->numero);
        else printf("\n");
}

void identificaNumeros(cel *lst) {
    cel *p;
    char *texto = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    for (p = lst; p != NULL; p = p->nova) {
        strcpy(texto, p->texto);
        
        if (strlen(texto) > 3)
            p->numero = 3;
        else if ((texto[0] == 'o' && texto[1] == 'n') || (texto[0] == 'o' && texto[2] == 'e') || (texto[1] == 'n' && texto[2] == 'e'))
            p->numero = 1;
        else if ((texto[0] == 't' && texto[1] == 'w') || (texto[0] == 't' && texto[2] == 'o') || (texto[1] == 'w' && texto[2] == 'o'))
            p->numero = 2;
    }
}

int main() {
    cel *s, *t;
    s = t = NULL;

    int n;
    char text[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(text, MAX_CHAR_LENGTH, stdin);
        text[strcspn(text, "\n")] = 0;
        insere(text, 0, &s, &t);
    }

    identificaNumeros(s);
    printaResultados(s);
    return 0;
}