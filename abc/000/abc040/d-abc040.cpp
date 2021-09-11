#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct unionfind {
  int parent;
  int size;
};

unionfind g[100001];

int dfs(int x) {
  if (g[x].parent == x) {
    return x;
  }
  int res = dfs(g[x].parent);
  g[x].size = g[res].size;
  g[x].parent = res;
  return res;
}

int main() {
  int n, m, a, b, y, q, v, w, ans[100000];
  vector<pair<int, pair<int, int> > > e, h;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> y;
    e.push_back({-y, {a, b}});
  }
  sort(e.begin(), e.end());
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> v >> w;
    h.push_back({-w, {v, i}});
  }
  sort(h.begin(), h.end());
  for (int i = 0; i <= n; i++) {
    g[i] = {i, 1};
  }
  int p = 0;
  for (int i = 0; i < q; i++) {
    while (p < m && h[i].first > e[p].first) {
      int l = dfs(e[p].second.first);
      int r = dfs(e[p].second.second);
      if (l != r) {
        g[r].size += g[l].size;
        g[l].parent = r;
      }
      p++;
    }
    ans[h[i].second.second] = g[dfs(h[i].second.first)].size;
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}