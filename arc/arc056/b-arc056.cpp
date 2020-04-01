#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
int n, m, u, v, g[200010], s;
vector<pair<int, int> > e;
vector<int> ans;

int dfs(int x) {
  if (g[x] == x) {
    return x;
  }
  return g[x] = dfs(g[x]);
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i <= n; i++) {
    g[i] = i;
  }
  g[s] = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    e.push_back({min(u, v), max(u, v)});
  }
  sort(e.begin(), e.end());
  int x = m - 1;
  for (int i = n; i > 0; i--) {
    while (x >= 0 && e[x].first >= i) {
      int a = dfs(e[x].first);
      int b = dfs(e[x].second);
      if (a < b) {
        g[b] = a;
      } else {
        g[a] = b;
      }
      x--;
    }
    dfs(i);
    if (g[i] == 0) {
      ans.push_back(i);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    printf("%d\n", ans[ans.size() - 1 - i]);
  }
}