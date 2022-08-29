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
using namespace std;
typedef long long ll;
#include <cstring>

int n, cnt;
vector<ll> id, c, ans;
vector<vector<int> > g;
vector<pair<int, int> > e;

void dfs(int x, int y) {
  id[x] = cnt++;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      ans[g[x][i]] = ans[x] + c[g[x][i]];
      dfs(g[x][i], x);
    }
  }
}

int main() {
  int a, b;
  cin >> n;
  g.resize(n);
  id.resize(n);
  c.resize(n);
  ans.resize(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    e.push_back({a, b});
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  ll q, t, x, y;
  cin >> q;
  while (q--) {
    cin >> t >> x >> y;
    x--;
    if (t == 1) {
      a = e[x].first;
      b = e[x].second;
    } else {
      a = e[x].second;
      b = e[x].first;
    }
    if (id[a] < id[b]) {
      c[0] += y;
      c[b] -= y;
    } else {
      c[a] += y;
    }
  }
  ans[0] = c[0];
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}
