#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula {
    char valor;
    struct celula *prox;
} celula;

typedef struct {
    celula *topo;
    int tamanho;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

void empilha(Pilha *p, char c) {
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) exit(1);
    nova->valor = c;
    nova->prox = p->topo;
    p->topo = nova;
    p->tamanho++;
}

char desempilha(Pilha *p) {
    if (p->topo == NULL) return '\0';
    celula *temp = p->topo;
    char valor = temp->valor;
    p->topo = temp->prox;
    p->tamanho--;
    free(temp);
    return valor;
}

int vazia(Pilha *p) {
    return p->topo == NULL;
}

void freePilha(Pilha *p) {
    while (!vazia(p)) {
        desempilha(p);
    }
}

int main() {
    const int MAX = 1000;
    char expression[MAX];
    
    while (scanf("%s", expression) != EOF) {
        Pilha pilha;
        inicializaPilha(&pilha);
        int correto = 1;
        
        for (int i = 0; expression[i] != '\0'; i++) {
            if (expression[i] == '(') {
                empilha(&pilha, '(');
            } else if (expression[i] == ')') {
                if (vazia(&pilha)) {
                    correto = 0;
                    break;
                }
                desempilha(&pilha);
            }
        }
        
        if (correto && !vazia(&pilha)) {
            correto = 0;
        }
        
        freePilha(&pilha);
        
        if (correto) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}