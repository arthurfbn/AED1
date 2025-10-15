#include <stdio.h>
#include <stdlib.h>

const int MAXSEQ = 100;
const int MAXPOPULACAO = 3000000;

void SelectionSort (int n, int v[]) {
    int i, j, min, x;
    for (i = 0; /*A*/ i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min]) min = j;

        x = v[i]; 
        v[i] = v[min]; 
        v[min] = x;
    }
}

int main(){
    int nc = 0;
    int n  = 0;
    int *v;

    scanf("%d", &nc);

    if(nc > MAXSEQ)
        return 1;
    
    for (int i = 0; i < nc; i++){
        scanf("%d", &n);
        if(n > MAXPOPULACAO)
            return 1;

        v = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++){
            scanf("%d", &v[j]);
            if(v[j] < 20 || v[j] > 230)
                return 1;            
        }
        SelectionSort(n, v);

        for (int j = 0; j < n; j++){
            printf("%d ", v[j]);
        }
        printf("\n");

        free(v);
    }
    return 0;
}

