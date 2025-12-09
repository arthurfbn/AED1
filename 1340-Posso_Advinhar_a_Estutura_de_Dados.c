#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} cel;

typedef struct {
    cel *topo;
} Pilha;

void empilha(Pilha *p, int v) {
    cel *n = malloc(sizeof(cel));
    n->valor = v;
    n->seg = p->topo;
    p->topo = n;
}

int desempilha(Pilha *p, int *ok) {
    if (!p->topo) {
        *ok = 0;
        return 0;
    }
    cel *q = p->topo;
    int v = q->valor;
    p->topo = q->seg;
    free(q);
    *ok = 1;
    return v;
}

typedef struct {
    int v[2000];
    int ini, fim;
} Fila;

void enfileira(Fila *f, int x) {
    f->v[f->fim++] = x;
}

int desenfileira(Fila *f, int *ok) {
    if (f->ini == f->fim) {
        *ok = 0;
        return 0;
    }
    *ok = 1;
    return f->v[f->ini++];
}

typedef struct {
    int v[2000];
    int n;
} Heap;

void heap_insere(Heap *h, int x) {
    int i = ++h->n;
    h->v[i] = x;
    while (i > 1 && h->v[i] > h->v[i/2]) {
        int t = h->v[i];
        h->v[i] = h->v[i/2];
        h->v[i/2] = t;
        i /= 2;
    }
}

int heap_remove(Heap *h, int *ok) {
    if (h->n == 0) {
        *ok = 0;
        return 0;
    }
    int r = h->v[1];
    h->v[1] = h->v[h->n--];
    int i = 1;
    while (1) {
        int e = 2*i, d = 2*i+1, m = i;
        if (e <= h->n && h->v[e] > h->v[m]) m = e;
        if (d <= h->n && h->v[d] > h->v[m]) m = d;
        if (m == i) break;
        int t = h->v[i];
        h->v[i] = h->v[m];
        h->v[m] = t;
        i = m;
    }
    *ok = 1;
    return r;
}

int main() {
    int n, op, x;
    while (scanf("%d", &n) == 1) {
        Pilha pilha = {NULL};
        Fila fila; fila.ini = fila.fim = 0;
        Heap heap; heap.n = 0;

        int sp = 1, sq = 1, sh = 1;

        for (int i = 0; i < n; i++) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &x);
                empilha(&pilha, x);
                enfileira(&fila, x);
                heap_insere(&heap, x);
            } else {
                scanf("%d", &x);
                int ok;

                int v1 = desempilha(&pilha, &ok);
                if (!ok || v1 != x) sp = 0;

                int v2 = desenfileira(&fila, &ok);
                if (!ok || v2 != x) sq = 0;

                int v3 = heap_remove(&heap, &ok);
                if (!ok || v3 != x) sh = 0;
            }
        }

        int sum = sp + sq + sh;

        if (sum == 0) printf("impossible\n");
        else if (sum > 1) printf("not sure\n");
        else if (sp) printf("stack\n");
        else if (sq) printf("queue\n");
        else printf("priority queue\n");
    }
    return 0;
}
