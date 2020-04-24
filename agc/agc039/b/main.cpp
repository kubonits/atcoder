#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int g[200][200], c[200], dis[200][200], n, ans;

int dfs(int x) {
  for (int i = 0; i < n; i++) {
    if (g[x][i] == 1 && c[i] == 0) {
      c[i] = c[x] * -1;
      if (dfs(i) == 0) {
        return 0;
      }
    } else if (g[x][i] == 1 && c[x] == c[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        g[i][j] = 1;
      }
    }
  }
  c[0] = 1;
  if (dfs(0) == 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      dis[i][j] = dis[j][i] = 1000;
      if (g[i][j] == 1) {
        dis[i][j] = dis[j][i] = 1;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans = max(ans, dis[i][j]);
    }
  }
  cout << ans + 1 << endl;
}