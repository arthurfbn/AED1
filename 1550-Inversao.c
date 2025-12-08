    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    const int MAX = 10000;

    typedef struct cel {
        int valor;
        struct cel *seg;
    } cel;

    int inverter(int num) {
        int invertido = 0;
        while (num > 0) {
            invertido = invertido * 10 + (num % 10);
            num /= 10;
        }
        return invertido;
    }

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
        if (*et == NULL)
            *et = *es = nova;
        else {
            (*et)->seg = nova;
            *et = nova;
        }
    }


    int bfs(int A, int B) {
        int dist[MAX]; 
        memset(dist, -1, sizeof(dist));  
        
        cel *s = NULL, *t = NULL;  
        dist[A] = 0;
        Insere(A, &s, &t);  
        
        while (s != NULL) {  
            int atual = Remove(&s, &t); 
            
            if (atual == B) return dist[atual];
            
            if (atual + 1 < MAX && dist[atual + 1] == -1) {
                dist[atual + 1] = dist[atual] + 1;
                Insere(atual + 1, &s, &t);
            }
            
            int invertido = inverter(atual);
            if (invertido < MAX && dist[invertido] == -1) {
                dist[invertido] = dist[atual] + 1;
                Insere(invertido, &s, &t); 
            }
        }
        
        return -1;  
    }

    int main() {
        int T;
        scanf("%d", &T);
        
        while (T--) {
            int A, B;
            scanf("%d %d", &A, &B);
            
            printf("%d\n", bfs(A, B));
        }
        
        return 0;
    }
