#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k, m, g[51][51] = {}, r, x, y, ans = 0, f[51] = {};
  vector<int> v[50];
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> m;
    v[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  cin >> r;
  for (int i = 0; i < r; i++) {
    cin >> x >> y;
    g[x][y] = 1;
    g[y][x] = 1;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      for (int l = j + 1; l < v[i].size(); l++) {
        if (g[v[i][j]][v[i][l]]) {
          f[v[i][j]] = 1;
          f[v[i][l]] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += f[i];
  }
  cout << ans << endl;
}