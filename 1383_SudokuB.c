#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *prox;
} celula;

typedef struct {
    celula *inicio;
    int tamanho;
} Linha;

typedef struct {
    Linha linhas[9];
} Matriz;

void inicializaMatriz(Matriz *m) {
    for (int i = 0; i < 9; i++) {
        m->linhas[i].inicio = NULL;
        m->linhas[i].tamanho = 0;
    }
}

void insereFim(Linha *linha, int valor) {
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) exit(1);
    nova->valor = valor;
    nova->prox = NULL;
    
    if (linha->inicio == NULL) {
        linha->inicio = nova;
    } else {
        celula *temp = linha->inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nova;
    }
    linha->tamanho++;
}

int getValor(Matriz *m, int i, int j) {
    celula *temp = m->linhas[i].inicio;
    for (int k = 0; k < j; k++) {
        temp = temp->prox;
    }
    return temp->valor;
}

void liberaMatriz(Matriz *m) {
    for (int i = 0; i < 9; i++) {
        celula *temp = m->linhas[i].inicio;
        while (temp != NULL) {
            celula *liberar = temp;
            temp = temp->prox;
            free(liberar);
        }
    }
}

int sudoku(Matriz *m) {
    int aux_i = 0;
    int aux_j = 0;
    
    for (int c = 0; c < 9; c++) {
        int flagRepeticao[10] = {0};
        for (int i = aux_i; i < aux_i + 3; i++) {
            for (int j = aux_j; j < aux_j + 3; j++) {
                int num = getValor(m, i, j);
                if (num < 0 || num > 9 || flagRepeticao[num] > 0)
                    return 0;
                flagRepeticao[num]++;
            }
        }
        aux_j += 3;
        if ((c + 1) % 3 == 0) {
            aux_i += 3;
            aux_j = 0;
        }
    }
    
    for (int i = 0; i < 9; i++) {
        int flagRepeticao[10] = {0};
        for (int j = 0; j < 9; j++) {
            int num = getValor(m, i, j);
            if (flagRepeticao[num] > 0)
                return 0;
            flagRepeticao[num]++;
        }
    }
    
    for (int i = 0; i < 9; i++) {
        int flagRepeticao[10] = {0};
        for (int j = 0; j < 9; j++) {
            int num = getValor(m, j, i);
            if (flagRepeticao[num] > 0)
                return 0;
            flagRepeticao[num]++;
        }
    }
    
    return 1;
}

int main() {
    int n = 0;
    
    scanf("%d", &n);
    
    for (int c = 0; c < n; c++) {
        Matriz m;
        inicializaMatriz(&m);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int valor;
                scanf("%d", &valor);
                insereFim(&m.linhas[i], valor);
            }
        }
        
        printf("Instancia %d\n", c + 1);
        if (sudoku(&m) == 0)
            printf("NAO\n\n");
        else
            printf("SIM\n\n");
        
        liberaMatriz(&m);
    }
    
    return 0;
}