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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll> > g(n + 1, vector<ll>(n + 1));
  vector<ll> a(m), b(m), c(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    g[a[i]][b[i]] = g[b[i]][a[i]] = c[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (!g[i][j] && i != j) {
        g[i][j] = 1000000000000000000;
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int flag = 0;
    if (g[a[i]][b[i]] < c[i]) {
      flag = 1;
    }
    for (int k = 1; k <= n; k++) {
      if (k != a[i] && k != b[i] && g[a[i]][k] + g[k][b[i]] <= c[i]) {
        flag = 1;
      }
    }
    ans += flag;
  }
  cout << ans << endl;
}
