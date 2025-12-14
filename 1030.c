#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int val;
    struct cel *prox;
} cel;

cel* cria_circular(int n) {
    cel *ini = NULL, *ant = NULL;
    for (int i = 1; i <= n; i++) {
        cel *novo = malloc(sizeof(cel));
        novo->val = i;
        if (!ini) {
            ini = novo;
        } else {
            ant->prox = novo;
        }
        ant = novo;
    }
    ant->prox = ini;
    return ini;
}

int josephus(int n, int k) {
    cel *p = cria_circular(n);
    cel *ant = p;

    while (ant->prox != p)
        ant = ant->prox;

    while (p->prox != p) {
        for (int i = 1; i < k; i++) {
            ant = p;
            p = p->prox;
        }
        ant->prox = p->prox;
        free(p);
        p = ant->prox;
    }

    int res = p->val;
    free(p);
    return res;
}

int main() {
    int NC;
    scanf("%d", &NC);

    for (int i = 1; i <= NC; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, josephus(n, k));
    }

    return 0;
}
