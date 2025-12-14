#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochila(int capacidade, int pesos[], int valores[], int n) {
    int dp[capacidade + 1];
    
    for (int i = 0; i <= capacidade; i++) {
        dp[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int c = capacidade; c >= pesos[i]; c--) {
            dp[c] = max(dp[c], dp[c - pesos[i]] + valores[i]);
        }
    }
    
    return dp[capacidade];
}

int main() {
    int C, F;
    int caso = 1;
    
    while (scanf("%d %d", &C, &F) && (C || F)) {
        int pesos[F];
        int valores[F];
        
        for (int i = 0; i < F; i++) {
            scanf("%d %d", &pesos[i], &valores[i]);
        }
        
        int resultado = mochila(C, pesos, valores, F);
        
        printf("Teste %d\n", caso);
        printf("%d\n\n", resultado);
        
        caso++;
    }
    
    return 0;
}