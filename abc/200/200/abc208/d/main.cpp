#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, m, a, b;
  ll c, ans = 0LL;
  cin >> n >> m;
  vector<vector<ll> > g(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    g[i][i] = 0LL;
    for (int j = i + 1; j < n; j++) {
      g[i][j] = g[j][i] = INF;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    a--;
    b--;
    g[a][b] = c;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        if (g[i][j] != INF) {
          ans += g[i][j];
        }
      }
    }
  }
  cout << ans << endl;
}