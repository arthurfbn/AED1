#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//returns the priority order from each class of operations
int priority(char op) {
    switch (op) {
        case '^': return 3;  
        case '*': case '/': return 2; 
        case '+': case '-': return 1;
        default: return 0;
    }
}

// This implementation uses stacks in arrays and is based on the explanation on this disciplin 
// guide's book 'Algoritmos em linguagem C' written by Paulo Feofiloff

char *InfixToPostfix(char infix[]) {
    char *postfix, x;
    char *p;
    int n = strlen(infix);
    int t = 0, i, j = 0;

    postfix = malloc((n + 1) * sizeof(char));
    p = malloc(n * sizeof(char));

    if (postfix == NULL || p == NULL) exit(1);

    for (i = 0; infix[i] != '\0'; i++) {
        switch (infix[i]) {
            case '(':
                p[t++] = infix[i];
                break;
            case ')':
                while (t > 0) {
                    x = p[--t];
                    if (x == '(') break;
                    postfix[j++] = x;
                }
                break;
            case '+':
            case '-':
                while (t > 0) {
                    x = p[t - 1];
                    if (x == '(') break;
                    --t;
                    postfix[j++] = x;
                }
                p[t++] = infix[i];
                break;
            case '*':
            case '/':
                while (t > 0) {
                    x = p[t - 1];
                    if (x == '(' || x == '+' || x == '-') break;
                    --t;
                    postfix[j++] = x;
                }
                p[t++] = infix[i];
                break;
            case '^':
                while (t > 0) {
                    x = p[t - 1];
                    if (x == '(') break;
                    if (priority(x) < priority(infix[i])) break;
                    --t;
                    postfix[j++] = x;
                }
                p[t++] = infix[i];
                break;
            default:
                postfix[j++] = infix[i];
                break;
        }
    }

    while (t > 0) {
        postfix[j++] = p[--t];
    }

    postfix[j] = '\0';
    free(p);
    return postfix;
}

int main() {
    int n;
    char infix[300];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", infix);
        char *postfix = InfixToPostfix(infix);
        printf("%s\n", postfix);
        free(postfix);
    }

    return 0;
}
