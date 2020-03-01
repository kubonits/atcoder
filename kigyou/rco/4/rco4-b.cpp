#include <cstdio>
#include <cstring>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int g[50][50];
int n, m;
int a[50][50], cnt, b[50][50];
vector<int> label[4];
vector<set<int> > slabel;
void dfs(int x, int y) {
  if (x != 0 && g[x - 1][y] != g[x][y] && a[x - 1][y] == a[x][y]) {
    g[x - 1][y] = g[x][y];
    dfs(x - 1, y);
  }
  if (y != 0 && g[x][y - 1] != g[x][y] && a[x][y - 1] == a[x][y]) {
    g[x][y - 1] = g[x][y];
    dfs(x, y - 1);
  }
  if (x != n - 1 && g[x + 1][y] != g[x][y] && a[x + 1][y] == a[x][y]) {
    g[x + 1][y] = g[x][y];
    dfs(x + 1, y);
  }
  if (y != n - 1 && g[x][y + 1] != g[x][y] && a[x][y + 1] == a[x][y]) {
    g[x][y + 1] = g[x][y];
    dfs(x, y + 1);
  }
}

int main() {
  int maxi, x, y, flag, d;
  char s[5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = -1;
    }
  }
  strcpy(s, "DURL");
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == -1) {
        g[i][j] = cnt;
        cnt++;
        dfs(i, j);
        label[a[i][j]].push_back(cnt - 1);
      }
    }
  }
  slabel.resize(cnt);
  for (int i = 0; i < n; i++) {
    for (int j = 0) }
  b[0][0] = 0;
  b[0][n - 1] = 1;
  b[n - 1][0] = 2;
  b[n - 1][n - 1] = 3;
  for (int i = 0; i < m; i++) {
    flag = 0;
    maxi = 0;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (b[j][k] == i % 4) {
          cnt = 0;
          for (int l = 1; l <= 5 && j + l < n; l++) {
            if (b[j + l][k] == -1) {
              cnt++;
            }
            if (a[j + l][k] != b[j + l][k] && a[j + l][k] == i % 4) {
              cnt += 10;
            } else if (a[j + l][k] == b[j + l][k] && a[j + l][k] != i % 4) {
              cnt -= 10;
            }

            if (maxi < cnt) {
              flag = 1;
              maxi = cnt;
              d = 0;
              x = j;
              y = k;
            }
          }
          cnt = 0;
          for (int l = 1; l <= 5 && j - l >= 0; l++) {
            if (b[j - l][k] == -1) {
              cnt++;
            }
            if (a[j - l][k] != b[j - l][k] && a[j - l][k] == i % 4) {
              cnt += 10;
            } else if (a[j - l][k] == b[j - l][k] && a[j - l][k] != i % 4) {
              cnt -= 10;
            }
            if (maxi < cnt) {
              flag = 1;
              maxi = cnt;
              d = 1;
              x = j;
              y = k;
            }
          }
          cnt = 0;
          for (int l = 1; l <= 5 && k + l < n; l++) {
            if (b[j][k + l] == -1) {
              cnt++;
            }
            if (a[j][k + l] != b[j][k + l] && a[j][k + l] == i % 4) {
              cnt += 10;
            } else if (a[j][k + l] == b[j][k + l] && a[j][k + l] != i % 4) {
              cnt -= 10;
            }
            if (maxi < cnt) {
              flag = 1;
              maxi = cnt;
              d = 2;
              x = j;
              y = k;
            }
          }
          cnt = 0;
          for (int l = 1; l <= 5 && k - l >= 0; l++) {
            if (b[j][k - 1] == -1) {
              cnt++;
            }
            if (a[j][k - l] != b[j][k - l] && a[j][k - l] == i % 4) {
              cnt += 10;
            } else if (a[j][k - l] == b[j][k - l] && a[j][k - l] != i % 4) {
              cnt -= 10;
            }
            if (maxi < cnt) {
              flag = 1;
              maxi = cnt;
              d = 3;
              x = j;
              y = k;
            }
          }
        }
      }
    }
    if (flag) {
      printf("%d %d %c\n", x, y, s[d]);
      if (d == 0) {
        for (int i = 1; i <= 5 && x + i < n; i++) {
          b[x + i][y] = b[x][y];
        }
      }
      if (d == 1) {
        for (int i = 1; i <= 5 && x - i >= 0; i++) {
          b[x - i][y] = b[x][y];
        }
      }
      if (d == 2) {
        for (int i = 1; i <= 5 && y + i < n; i++) {
          b[x][y + i] = b[x][y];
        }
      }
      if (d == 3) {
        for (int i = 1; i <= 5 && y - i >= 0; i++) {
          b[x][y - i] = b[x][y];
        }
      }
    } else {
      printf("-1\n");
    }
  }
}