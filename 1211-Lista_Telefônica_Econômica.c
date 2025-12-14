#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000
#define MAXL 205

char phones[MAXN][MAXL];

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int common_prefix(const char *a, const char *b) {
    int i = 0;
    while (a[i] && a[i] == b[i]) i++;
    return i;
}

int main() {
    int N;

    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            scanf("%s", phones[i]);
        }

        qsort(phones, N, sizeof(phones[0]), cmp);

        long long saved = 0;
        for (int i = 1; i < N; i++) {
            saved += common_prefix(phones[i - 1], phones[i]);
        }

        printf("%lld\n", saved);
    }

    return 0;
}
