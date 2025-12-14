#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    char c;
    struct Cel *prox;
} Cel;

int main() {
    char linha[100005];

    while (fgets(linha, sizeof(linha), stdin)) {
        Cel *inicio = NULL;
        Cel *fim = NULL;
        Cel *atual = NULL;

        for (int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++) {
            if (linha[i] == '[') {
                atual = NULL;
            } 
            else if (linha[i] == ']') {
                atual = fim;
            } 
            else {
                Cel *Celvo = (Cel *)malloc(sizeof(Cel));
                Celvo->c = linha[i];
                Celvo->prox = NULL;

                if (inicio == NULL) {
                    inicio = fim = Celvo;
                    atual = Celvo;
                } 
                else if (atual == NULL) {
                    Celvo->prox = inicio;
                    inicio = Celvo;
                    atual = Celvo;
                } 
                else {
                    Celvo->prox = atual->prox;
                    atual->prox = Celvo;
                    atual = Celvo;
                    if (Celvo->prox == NULL)
                        fim = Celvo;
                }
            }
        }

        Cel *p = inicio;
        while (p) {
            putchar(p->c);
            Cel *tmp = p;
            p = p->prox;
            free(tmp);
        }
        putchar('\n');
    }

    return 0;
}
