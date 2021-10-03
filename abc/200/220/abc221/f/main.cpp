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
#define MOD 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int n;
vector<int> g[200001];
int d[200001];
pair<int, int> l[200001];

void dfs(int x, int y, int z) {
  d[x] = z;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      dfs(g[x][i], x, z + 1);
    }
  }
}

int dfs2(int x, int y) {
  int res = 0;
  l[x] = {0, -1};
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      int num = dfs2(g[x][i], x);
      if (num > res) {
        res = num;
        l[x] = {num, g[x][i]};
      }
    }
  }
  return res + 1;
}

pair<int, int> calc(int x, int y, int z) {
  pair<int, int> res = {0, 0};
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      pair<int, int> p = calc(g[x][i], x, z);
    }
  }
  return res;
}

int main() {
  int u, v, md, p;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0, 0);
  md = 0;
  for (int i = 1; i <= n; i++) {
    if (md < d[i]) {
      md = d[i];
      p = i;
    }
  }
  dfs2(p, -1);
  vector<int> x;
  while (p != -1) {
    x.push_back(p);
    p = l[p].second;
  }
  for (int i = 0; i < x.size(); i++) {
    cout << x[i] << " ";
  }
  cout << endl;
  cout << x[x.size() / 2] << endl;
  calc(x[x.size() / 2], 0, x[x.size() / 2]);
}
