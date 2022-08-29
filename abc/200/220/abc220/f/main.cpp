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

ll n;
vector<ll> g[200001], ans(200001), sub(200001);

pair<ll, ll> dfs(int x, int y) {
  sub[x] = 1;
  pair<ll, ll> res = {0, 1};
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      pair<ll, ll> p = dfs(g[x][i], x);
      res.first += p.first + p.second;
      res.second += p.second;
      sub[x] += sub[g[x][i]];
    }
  }
  return res;
}

void dfs2(int x, int y) {
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      ans[g[x][i]] = ans[x] + n - 2 * sub[g[x][i]];
      dfs2(g[x][i], x);
    }
  }
}

int main() {
  int u, v;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  ans[1] = dfs(1, 0).first;
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
}
