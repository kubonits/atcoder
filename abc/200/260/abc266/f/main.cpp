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

vector<vector<int> > g(200001);
vector<int> pa(200001), visited(200001), depth(200001);
set<int> s;

void dfs(int x, int y) {
  depth[x] = depth[y] + 1;
  pa[x] = y;
  visited[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    if (visited[g[x][i]] == 0) {
      dfs(g[x][i], x);
    } else if (g[x][i] != y) {
      int u, v;
      u = x;
      v = g[x][i];
      while (u != v) {
        if (depth[u] > depth[v]) {
          s.insert(u);
          u = pa[u];
        } else if (depth[u] < depth[v]) {
          s.insert(v);
          v = pa[v];
        } else {
          s.insert(u);
          u = pa[u];
          s.insert(v);
          v = pa[v];
        }
      }
      s.insert(u);
    }
  }
}

void dfs2(int x, int y) {
  pa[x] = y;
  for (int i = 0; i < g[x].size(); i++) {
    if (s.find(g[x][i]) == s.end() && pa[g[x][i]] != y) {
      dfs2(g[x][i], y);
    }
  }
}

int main() {
  int n, u, v, q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  for (int i = 0; i <= n; i++) {
    pa[i] = 0;
  }
  for (auto &&x : s) {
    dfs2(x, x);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> u >> v;
    cout << (pa[u] == pa[v] ? "Yes" : "No") << endl;
  }
}
