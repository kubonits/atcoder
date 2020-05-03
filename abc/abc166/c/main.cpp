#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int g[100001], h[100000];

int dfs(int x) {
  if (g[x] == x) {
    return x;
  } else {
    g[x] = dfs(g[x]);
  }
}

int main() {
  int n, m, a, b, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    g[i] = 1;
    cin >> h[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    if (h[a] <= h[b]) {
      g[a] = 0;
    }
    if (h[a] >= h[b]) {
      g[b] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    ans += g[i];
  }
  cout << ans << endl;
}