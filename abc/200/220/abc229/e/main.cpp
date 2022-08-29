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

int n, m;

struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[200001];

void init() {
  for (int i = 0; i <= n; i++) {
    g[i].parent = i;
    g[i].node = 1;
    g[i].edge = 0;
  }
}

int ufind(int x) {
  if (x == g[x].parent) {
    return x;
  }
  int res = ufind(g[x].parent);
  g[x].node = g[res].node;
  g[x].edge = g[res].edge;
  g[x].parent = res;
  return res;
}

void umerge(int x, int y) {
  if (x > y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  g[x].node += g[y].node;
  g[x].edge += g[y].edge + 1;
  g[y].parent = x;
}

int main() {
  int a, b;
  cin >> n >> m;
  vector<vector<int> > v(n);
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
  }
  init();
  set<int> s;
  ans.push_back(0);
  for (int i = n - 1; i >= 0; i--) {
    s.insert(i);
    for (int j = 0; j < v[i].size(); j++) {
      int x = ufind(v[i][j]);
      if (i != x) {
        s.erase(x);
        umerge(i, x);
      }
    }
    ans.push_back(s.size());
  }
  for (int i = 0; i < n; i++) {
    cout << ans[n - 1 - i] << endl;
  }
}
