#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//The implentation of Stacks' algorithm is based on the guide's book  of this disciplin 'Algoritmos em linguagem C' written by Paulo Feofiloff

typedef struct cel {
    int valor;
    struct cel *seg;
} cel;

void Empilha(int y, cel *p) {
    cel *nova = malloc(sizeof(cel));
    nova->valor = y;
    nova->seg = p->seg;
    p->seg = nova;
}

int Desempilha(cel *p) {
    int x;
    cel *q = p->seg;
    x = q->valor;
    p->seg = q->seg;
    free(q);
    return x;
}

int topo(cel *p) {
    return (p->seg == NULL) ? -1 : p->seg->valor;
}

int pode_colocar(int num, int topo) {
    int soma = num + topo;
    int raiz = sqrt(soma);
    return raiz * raiz == soma;
}

int calcula_max_bolas(int N) {
    cel pilhas[N];
    for (int i = 0; i < N; i++) {
        pilhas[i].seg = NULL;
    }
    
    int bola = 1;
    while (1) {
        int colocado = 0;
        for (int i = 0; i < N; i++) {
            if (pilhas[i].seg == NULL || pode_colocar(bola, topo(&pilhas[i]))) {
                Empilha(bola, &pilhas[i]);
                colocado = 1;
                break;
            }
        }
        if (!colocado) break;
        bola++;
    }
    return bola - 1;
}

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", calcula_max_bolas(N));
    }
    return 0;
}
