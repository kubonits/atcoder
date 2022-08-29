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
  int n, m, u, v, ans = 0;
  cin >> n >> m;
  vector<vector<int> > g(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (g[i][j]) {
        for (int k = j + 1; k <= n; k++) {
          if (g[i][k] == 1 && g[j][k] == 1) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
