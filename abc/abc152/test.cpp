#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<int, int> g[100001];

int dfs(int x) {
  if (x == g[x].first) {
    return x;
  }
  int y = dfs(g[x].first);
  /*g[x].second += g[g[x].first].second;
  g[x].first = y;*/
  return y;
}

int main(int argc, char *argv[]) {
  int n, q, a, b, c, ans = 0;
  cin >> n >> q;
  for (int i = 0; i <= n; i++) {
    g[i] = {i, 0};
  }
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> c;
    if (c < 0) {
      c *= -1;
      a ^= b;
      b ^= a;
      a ^= b;
    }
    int x, y;
    x = dfs(a);
    y = dfs(b);
    if (x != y) {
      if (-g[a].second < -g[b].second + c) {
        g[y].first = x;
        g[y].second = c + g[a].second - g[b].second;
      } else {
        g[x].first = y;
        g[x].second = c + g[b].second - g[a].second;
      }
    }
    if (x == y && g[a].second != g[b].second - c) {
      cout << a << " " << b << " " << c << endl;
      for (int i = 1; i <= n; i++) {
        cout << i << " " << g[i].first << " " << g[i].second << endl;
      }
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, g[i].second);
  }
  if (ans > 100) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
