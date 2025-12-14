#include <stdio.h>
#include <string.h>

typedef struct {
    int ascii;
    int freq;
} Item;

int main() {
    char linha[1100];
    int primeiroCaso = 1;

    while (fgets(linha, sizeof(linha), stdin)) {
        int cnt[256] = {0};

        int len = strlen(linha);
        for (int i = 0; i < len; i++) {
            if (linha[i] != '\n' && linha[i] != '\r') {
                cnt[(unsigned char)linha[i]]++;
            }
        }

        Item v[256];
        int qtd = 0;

        for (int i = 0; i < 256; i++) {
            if (cnt[i] > 0) {
                v[qtd].ascii = i;
                v[qtd].freq = cnt[i];
                qtd++;
            }
        }

        for (int i = 0; i < qtd; i++) {
            for (int j = i + 1; j < qtd; j++) {
                if (v[i].freq > v[j].freq ||
                   (v[i].freq == v[j].freq && v[i].ascii < v[j].ascii)) {
                    Item aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }

        if (!primeiroCaso)
            printf("\n");
        primeiroCaso = 0;

        for (int i = 0; i < qtd; i++) {
            printf("%d %d\n", v[i].ascii, v[i].freq);
        }
    }

    return 0;
}
