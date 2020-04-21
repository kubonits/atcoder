#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;

int g[100001];
int f[100001];

int dfs(int x) {
  if (x == g[x]) {
    return x;
  }
  return g[x] = dfs(g[x]);
}

int main() {
  int n, m, x, y, l, r;
  ll a, ans = 0LL;
  priority_queue<pair<ll, pair<int, int> > > q;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    q.push({-a, {i, i}});
    g[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> a;
    q.push({-a, {x, y}});
  }
  while (!q.empty()) {
    a = -q.top().first;
    l = q.top().second.first;
    r = q.top().second.second;
    x = dfs(l);
    y = dfs(r);
    q.pop();
    if (f[x] == 0 && f[y] == 0 && x != y) {
      g[y] = x;
      ans += a;
    } else if (f[x] == 0 && f[y] == 0 && l == r) {
      f[x] = 1;
      ans += a;
    } else if (f[x] == 1 && f[y] == 0) {
      g[y] = x;
      ans += a;
    } else if (f[x] == 0 && f[y] == 1) {
      g[x] = y;
      ans += a;
    }
  }
  cout << ans << endl;
}