#include <cstdio>

int w, h, p;
int z[20][20], g[20][20];

void dfs(int x, int y) {
  g[x][y] = 1;
  if (x != 0 && g[x - 1][y] == 0 && z[x - 1][y] < z[x][y]) {
    dfs(x - 1, y);
  }
  if (x != h - 1 && g[x + 1][y] == 0 && z[x + 1][y] < z[x][y]) {
    dfs(x + 1, y);
  }
  if (y != 0 && g[x][y - 1] == 0 && z[x][y - 1] < z[x][y]) {
    dfs(x, y - 1);
  }
  if (y != w - 1 && g[x][y + 1] == 0 && z[x][y + 1] < z[x][y]) {
    dfs(x, y + 1);
  }
}

int main() {
  int x, y, ans;
  scanf("%d%d%d", &w, &h, &p);
  while (w || h || p) {
    ans = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &z[i][j]);
        g[i][j] = 0;
      }
    }
    for (int i = 0; i < p; i++) {
      scanf("%d%d", &y, &x);
      if (g[x][y] == 0) {
        dfs(x, y);
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        ans += g[i][j];
      }
    }
    printf("%d\n", ans);
    scanf("%d%d%d", &w, &h, &p);
  }
}