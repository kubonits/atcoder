#include <cstdio>
using namespace std;

int a[3], x[3][3], y[3], ans, flag[10];

void dfs(int num) {
  if (num == y[2]) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < a[i]; j++) {
        if (i != 0 && x[i][j] <= x[i - 1][j]) {
          return;
        }
        if (j != 0 && x[i][j] <= x[i][j - 1]) {
          return;
        }
      }
    }
    ans++;
    return;
  }
  for (int i = 1; i <= y[2]; i++) {
    if (flag[i] == 0) {
      flag[i] = 1;
      if (num < y[0]) {
        x[0][num] = i;
      } else if (num < y[1]) {
        x[1][num - y[0]] = i;
      } else {
        x[2][num - y[1]] = i;
      }
      dfs(num + 1);
      flag[i] = 0;
    }
  }
}

int main() {
  scanf("%d%d%d", &a[0], &a[1], &a[2]);
  y[0] = a[0];
  y[1] = y[0] + a[1];
  y[2] = y[1] + a[2];
  dfs(0);
  printf("%d\n", ans);
}