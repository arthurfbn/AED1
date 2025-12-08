#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} cel;

int Remove(cel **es, cel **et) {
    cel *p;
    int x;
    p = *es;
    x = p->valor;
    *es = p->seg;
    free(p);
    if (*es == NULL) *et = NULL;
    return x;
}

void Insere(int y, cel **es, cel **et) {
    cel *nova;
    nova = malloc(sizeof(cel));
    nova->valor = y;
    nova->seg = NULL;
    if (*et == NULL) *et = *es = nova;
    else {
        (*et)->seg = nova;
        *et = nova;
    }
}

int main() {
    int N, M;
    scanf("%d", &N);

    cel *s = NULL, *t = NULL; 

    for (int i = 0; i < N; i++) {
        int id;
        scanf("%d", &id);
        Insere(id, &s, &t);
    }

    scanf("%d", &M);

    int *saidas = malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &saidas[i]);
    }

    cel *temp_s = NULL, *temp_t = NULL;

    while (s != NULL) {
        int id = Remove(&s, &t);
        int saiu = 0;

        for (int i = 0; i < M; i++) {
            if (id == saidas[i]) {
                saiu = 1;
                break;
            }
        }
        if (!saiu) Insere(id, &temp_s, &temp_t);
    }

    int primeiro = 1;
    while (temp_s != NULL) {
        int id = Remove(&temp_s, &temp_t);
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", id);
        primeiro = 0;
    }
    printf("\n");

    free(saidas);

    return 0;
}
