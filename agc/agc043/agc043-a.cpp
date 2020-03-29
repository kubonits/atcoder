#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int h, w;
char s[100][110];
int g[100][100];

void dfs(int x, int y) {
  if (x < h - 1 && s[x][y] == s[x + 1][y]) {
  }
}

int main() {
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      g[i][j] = i * 100 + j;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] == i * 100 + j) {
        dfs(i, j);
      }
    }
  }
}