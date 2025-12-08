#include<stdio.h>

int sudoku(int mat[9][9]){
    int aux_i = 0; 
    int aux_j = 0;
    //Verificando condições verdade para cada subgrid 3x3
    for(int c = 0; c < 9; c++){                         //Iterando um total de 9 subgrids
        int flagRepeticao[10] = {0};
        for (int i = aux_i; i < aux_i + 3; i++){
            for (int j = aux_j; j < aux_j + 3; j++){
                int num = mat[i][j];
                if(num < 0 || num > 9 || flagRepeticao[num] > 0)
                    return 0;

                flagRepeticao[num]++;
            }
        }                      
        aux_j += 3;                                     //Iterando blocos por coluna: bloco 1 (a00, a22); bloco 2 (a03, a25)...
        if ((c + 1) % 3 == 0){
            aux_i += 3;                                 // Mudando a linha do bloco 
            aux_j = 0;                                  //cel começo de cada nova linha do bloco, a coluna volta ao início
        }
    }

    //Verificando condições verdade para cada linha
    for (int i = 0; i < 9; i++) {
        int flagRepeticao[10] = {0};
        for (int j = 0; j < 9; j++) {
            int num = mat[i][j];
            if (flagRepeticao[num] > 0)                 // Se a condição for verdadeira, quer dizer que o mesmo número já esteve nessa coluna, ocorrendo duplicata
                return 0;                               // Número duplicado na linha
            
            flagRepeticao[num]++;                       // Marca o número como presente
        }
    }

    // Verificando condições verdade para cada coluna
    for (int i = 0; i < 9; i++) {
        int flagRepeticao[10] = {0}; 
        for (int j = 0; j < 9; j++) {
            int num = mat[j][i];
            if (flagRepeticao[num] > 0)                 // Se a condição for verdadeira, quer dizer que o mesmo número já esteve nessa coluna, ocorrendo duplicata
                return 0;                               // Número duplicado na coluna
            
            flagRepeticao[num]++;                       // Marca o número como presente
        }
    }

    return 1;
    
}

int main(){
    int teste_sudo[9][9];
    int n = 0;

    scanf("%d", &n);
    for (int c = 0; c < n; c++){
        for(int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf("%d", &teste_sudo[i][j]);
            }
        }
        printf("Instancia %d\n", c + 1);
        if(sudoku(teste_sudo) == 0)
            printf("NAO\n\n");
        else
            printf("SIM\n\n");

    }
}
