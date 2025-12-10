#include <stdio.h>
#include <string.h>

typedef struct {
    char elementos[1000];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

void empilha(Pilha *p, char c) {
    if (p->topo < 999) {
        p->topo++;
        p->elementos[p->topo] = c;
    }
}

char desempilha(Pilha *p) {
    if (p->topo < 0) return '\0';
    char valor = p->elementos[p->topo];
    p->topo--;
    return valor;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int main() {
    const int MAX = 1000;
    char expression[MAX];
    
    while (scanf("%s", expression) != EOF) {
        Pilha pilha;
        inicializa(&pilha);
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
        
        if (correto) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}