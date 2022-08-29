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
typedef pair<int, pair<int, int> > pipii;
typedef pair<pair<int, int>, pair<int, int> > piipii;
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
  int q, a, b, c, u, v, w;
  cin >> n >> m >> q;
  vector<int> ans(q);
  priority_queue<pipii, vector<pipii>, greater<pipii> > qe;
  priority_queue<piipii, vector<piipii>, greater<piipii> > qq;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    qe.push({c, {a, b}});
  }
  for (int i = 0; i < q; i++) {
    cin >> u >> v >> w;
    qq.push({{w, i}, {u, v}});
  }
  init();
  while (!qe.empty() && !qq.empty()) {
    int x = qe.top().first;
    int y = qq.top().first.first;
    // cout << x << " " << y << endl;
    if (x < y) {
      x = ufind(qe.top().second.first);
      y = ufind(qe.top().second.second);
      if (x != y) {
        umerge(x, y);
      }
      qe.pop();
    } else {
      x = ufind(qq.top().second.first);
      y = ufind(qq.top().second.second);
      // cout << x << " " << y << endl;
      if (x != y) {
        // cout << qq.top().first.second << endl;
        ans[qq.top().first.second] = 1;
      }
      qq.pop();
    }
  }
  for (int i = 0; i < q; i++) {
    cout << (ans[i] ? "Yes" : "No") << endl;
  }
}
