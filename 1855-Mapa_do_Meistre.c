#include <stdio.h>
#include <stdlib.h>

// This implementation is a simulation of graphs´ use

int isArrow(char c) {
  return c == '>' || c == 'v' || c == '<' || c == '^';
}

int setDirection(char c) {
  if (c == '>') return 1;
  if (c == 'v') return 2;
  if (c == '<') return 3;
  return 4;
}

int setX(int x, int d) {
  if (d == 1) return ++x;
  if (d == 3) return --x;
  return x;
}

int setY(int y, int d) {
  if (d == 2) return ++y;
  if (d == 4) return --y;
  return y;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    char **map = (char **)malloc(y * sizeof(char *));
    int **walk = (int **)malloc(y * sizeof(int *));
    for (int i = 0; i < y; i++) {
      map[i] = (char *)malloc(x * sizeof(char));
      walk[i] = (int *)calloc(x, sizeof(int));
    }

    for (int i = 0; i < y; i++) {
      for (int j = 0; j < x; j++) {
        scanf(" %c", &map[i][j]);
      }
    }

    int i = 0, j = 0, direction = 1, win = 0;

    while (walk[i][j] == 0 && !win) {
      char c = map[i][j];

      if (c == '*') {
        win = 1;
        break;
      }

      if (isArrow(c)) {
        walk[i][j] = 1;
        direction = setDirection(c);
      }

      int aux_i = setY(i, direction);
      int aux_j = setX(j, direction);

      if (aux_i < 0 || aux_i >= y || aux_j < 0 || aux_j >= x) break;

      i = aux_i;
      j = aux_j;
    }

    if (win) printf("*\n");
    else printf("!\n");

    for (int i = 0; i < y; i++) {
      free(map[i]);
      free(walk[i]);
    }
    free(map);
    free(walk);

    return 0;
}
