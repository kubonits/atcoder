#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int n = 4, x[5], y[5];

int dfs2(int a) {
  if (a == n) {
    for (int i = 0; i < n; i++) {
      printf("%d ", x[i]);
    }
    printf("OK ");
    for (int i = 0; i < n; i++) {
      printf("%d ", y[i]);
    }
    printf("\n");
    return 1;
  }
  int flag;
  for (int i = 0; i < n; i++) {
    if (a == 0) {
      y[a] = i;
      if (dfs2(a + 1)) {
        return 1;
      }
    }
    flag = 1;
    for (int j = 0; j < a; j++) {
      if (y[j] == i) {
        flag = 0;
      }
    }
    if (flag & x[y[a - 1]] != i) {
      y[a] = i;
      if (dfs2(a + 1)) {
        return 1;
      }
    }
  }
  return 0;
}

void dfs1(int a) {
  if (a == n) {
    if (!dfs2(0)) {
      for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
      }
      printf("NO\n");
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i != a) {
      x[a] = i;
      dfs1(a + 1);
    }
  }
}
int main() { dfs1(0); }