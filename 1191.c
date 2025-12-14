#include <stdio.h>
#include <string.h>

char pre[30], in[30];

void solve(int pre_i, int pre_f, int in_i, int in_f) {
    if (pre_i > pre_f || in_i > in_f) return;

    char root = pre[pre_i];

    int k;
    for (k = in_i; k <= in_f; k++) {
        if (in[k] == root) break;
    }

    int left_size = k - in_i;

    solve(pre_i + 1, pre_i + left_size, in_i, k - 1);
    solve(pre_i + left_size + 1, pre_f, k + 1, in_f);

    printf("%c", root);
}

int main() {
    while (scanf("%s %s", pre, in) != EOF) {
        int n = strlen(pre);
        solve(0, n - 1, 0, n - 1);
        printf("\n");
    }
    return 0;
}
