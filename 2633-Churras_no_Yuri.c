#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
  char carne[21];
  int validade;
  struct cel* prox;
} cel;

cel* insere(char* carne, int validade, cel *ultima) {
  cel *nova = (cel*) malloc(sizeof(cel));
  strcpy(nova->carne, carne);
  nova->validade = validade;
  nova->prox = ultima->prox;
  ultima->prox = nova;
  return nova;
}

void ordena(cel *c) {
  char temp_carne[21];
  int temp_validade;

  for (cel* p = c->prox; p != NULL; p = p->prox) {
    for (cel* q = p->prox; q != NULL; q = q->prox) {
      if (p->validade > q->validade) {
        strcpy(temp_carne, p->carne);
        strcpy(p->carne, q->carne);
        strcpy(q->carne, temp_carne);

        temp_validade = p->validade;
        p->validade = q->validade;
        q->validade = temp_validade;
      }
    }
  }
}

void imprime(cel *c) {
  for (cel *p = c->prox; p != NULL; p = p->prox) {
    printf("%s", p->carne);
    if (p->prox == NULL) printf("\n");
    else                 printf(" ");
    
  }
}

void libera(cel* c) {
  cel* p = c;
  while (p != NULL) {
    cel* temp = p->prox;
    free(p);
    p = temp;
  }
}

int main() {
  int n, validade;
  char carne[21];
  
  while (scanf("%d", &n) != EOF) {
    cel* c = (cel*) malloc(sizeof(cel));
    cel* ultima = c;

    for (int i = 0; i < n; i++) {
      scanf("%s %d", carne, &validade);
      ultima = insere(carne, validade, ultima);
    }
    
    ordena(c);
    imprime(c);
    libera(c);
  }

  return 0;
}
