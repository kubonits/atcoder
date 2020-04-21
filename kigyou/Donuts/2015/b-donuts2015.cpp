#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, a[17], b[50], c[50], I[50][16];

int dfs(int x, vector<int> v) {
  if (x == n && v.size() != 9) {
    return 0;
  }
  if (x == n) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
      res += a[v[i]];
    }
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int j = 0; j < c[i]; j++) {
        for (int k = 0; k < v.size(); k++) {
          if (I[i][j] == v[k]) {
            cnt++;
          }
        }
      }
      if (cnt >= 3) {
        res += b[i];
      }
    }
    return res;
  }
  int res = 0;
  v.push_back(x + 1);
  res = dfs(x + 1, v);
  v.pop_back();
  res = max(res, dfs(x + 1, v));
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i + 1]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &b[i], &c[i]);
    for (int j = 0; j < c[i]; j++) {
      scanf("%d", &I[i][j]);
    }
  }
  vector<int> v;
  int ans = dfs(0, v);
  printf("%d\n", ans);
}