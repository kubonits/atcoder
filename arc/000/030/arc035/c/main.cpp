#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll g[401][401];

int main() {
  int n, m, a, b, k;
  ll ans = 0LL, c;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      g[i][j] = g[j][i] = 1000000LL;
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    g[a][b] = min(g[a][b], c);
    g[b][a] = min(g[b][a], c);
  }
  for (int l = 1; l <= n; l++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], g[i][l] + g[l][j]);
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += g[i][j];
    }
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> a >> b >> c;
    if (g[a][b] > c) {
      ans -= (g[a][b] - c);
      g[a][b] = c;
      g[b][a] = c;
      for (int x = 1; x <= n; x++) {
        if (g[x][a] > g[x][b] + g[b][a]) {
          ans += (g[x][b] + g[b][a]) - g[x][a];
          g[x][a] = g[a][x] = g[x][b] + g[b][a];
        }
        if (g[x][b] > g[x][a] + g[a][b]) {
          ans += (g[x][a] + g[a][b]) - g[x][b];
          g[x][b] = g[b][x] = g[x][a] + g[a][b];
        }
      }
      for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
          if (g[x][y] > g[x][a] + g[a][y]) {
            ans -= g[x][y];
            g[x][y] = g[y][x] = g[x][a] + g[a][y];
            ans += g[x][y];
          }
          if (g[x][y] > g[x][b] + g[b][y]) {
            ans -= g[x][y];
            g[x][y] = g[y][x] = g[x][b] + g[b][y];
            ans += g[x][y];
          }
        }
      }
    }
    cout << ans << endl;
  }
}