#include <stdio.h>

void separa(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo = arr[alto];
        int i = baixo - 1;

        for (int j = baixo; j < alto; j++) {
            if (arr[j] < pivo) {
                i++;
                separa(&arr[i], &arr[j]);
            }
        }
        separa(&arr[i + 1], &arr[alto]);
        int p = i + 1;

        quicksort(arr, baixo, p - 1);
        quicksort(arr, p + 1, alto);
    }
}

int busca_binaria(int arr[], int len, int chave) {
    int esq = 0, dir = len - 1, meio, found = -1;
    
    while (esq <= dir) {
        meio = esq + (dir - esq) / 2;
        if (arr[meio] == chave) {
            found = meio;
            dir = meio - 1;
        }else if (arr[meio] < chave) 
            esq = meio + 1;
        else 
            dir = meio - 1;
    }
    return found;
}

int main() {
    int n, q, caso = 1;
    
    while (1) {
        scanf("%d %d", &n, &q);
        if (n == 0 && q == 0) break;
        
        int marmores[n], consultas[q];
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &marmores[i]);
        }
        
        for (int i = 0; i < q; i++) {
            scanf("%d", &consultas[i]);
        }
        
        quicksort(marmores, 0, n - 1);
        
        printf("CASE# %d:\n", caso++);
  
        for (int i = 0; i < q; i++) {
            int resultado = busca_binaria(marmores, n, consultas[i]);
            if (resultado != -1) {
                printf("%d found at %d\n", consultas[i], resultado + 1);
            } else {
                printf("%d not found\n", consultas[i]);
            }
        }
    }
    
    return 0;
}
