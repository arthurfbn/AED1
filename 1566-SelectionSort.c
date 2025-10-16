/*
------------------------------------------------------------
|  Problem: 1566 - Height
|  Author : Neilor Tonin (URI / beecrowd)
|  Timelimit: 4 seconds
------------------------------------------------------------

Full of good ideas, now, the Brazilian government decided to 
create the "height benefit". This way, you were instructed to 
survey the height of the population of various cities and to 
sort this population in ascending order of height. You know 
that the cities that you have to do this don't have more than 
3 million people and, according to the IBGE, in these cities, 
no one person has more than 230 cm.

------------------------------------------------------------
Input
------------------------------------------------------------
The input contains many test cases. The first line of input 
contains an integer NC (NC < 100) that indicates the amount of 
test cases (cities). 

For each test case:
 - The first line contains an integer N (1 < N ≤ 3000000), 
   indicating the amount of people in the city.
 - The next line contains N integers h (20 ≤ h ≤ 230), each 
   representing the height of a citizen in centimeters.
 - Heights are separated by a blank space.

------------------------------------------------------------
Output
------------------------------------------------------------
For each test case, print a line containing all numbers 
representing the height of all citizens (in cm) in ascending 
order, separated by a blank space.

------------------------------------------------------------
Observation
------------------------------------------------------------
The input file is very large, so you need to use fast input 
and output methods.

------------------------------------------------------------
Sample Input                      Sample Output
------------------------------------------------------------
6
10
65 31 37 37 72 76 61 35 57 37
12
45 186 185 55 51 51 22 78 64 26 49 21
10
20 93 203 67 64 225 112 81 58 180
8
169 189 220 228 68 32 214 180
6
133 55 67 166 112 41
4
39 38 120 55

31 35 37 37 37 57 61 65 72 76
21 22 26 45 49 51 51 55 64 78 185 186
20 58 64 67 81 93 112 180 203 225
32 68 169 180 189 214 220 228
41 55 67 112 133 166
38 39 55 120
------------------------------------------------------------
*/

//Tentei de todas as formas fazer passar nos testes limitados à até 4s
//com tamanho máximo do vetor de alturas de 3000000, porém o método se
//mostrou incapaz e limitado para essa resolução. Tentei realizar
//o alocamento dinâmico e estático, mas ambos estouraram o limite de 
//tempo nos testes do beecrowd retornando 'time limit exceeded'

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

    int *v = (int *) malloc(MAXPOPULACAO * sizeof(int));
    if (v == NULL){
        printf("Erro ao alocar memória");
        return 1;
    }

    scanf("%d", &nc);
    if(nc <= 1 || nc > MAXSEQ)  
        return 1;
    
    for (int i = 0; i < nc; i++){
        scanf("%d", &n);
        if(n > MAXPOPULACAO)
            return 1;
        
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
    }

    free(v);
    return 0;
}
