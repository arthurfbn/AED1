#include <stdio.h>
#include <stdlib.h>

const int MAXSEQ = 100;
const int MAXPOPULACAO = 3000000;

void InsertionSort (int n, int v[]) {
    int i, j, x;
    for (j = 1; /*A*/ j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
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
        InsertionSort(n, v);

        for (int j = 0; j < n; j++){
            printf("%d ", v[j]);
        }
        printf("\n");

        free(v);
    }
    return 0;
}

