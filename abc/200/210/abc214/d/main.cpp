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

int u, v;
vector<pair<ll, pair<ll, ll> > > e;
ll ans = 0LL, w;

int n, m;

struct unionfind {
  int parent;
  ll node;
  int edge;
};
unionfind g[100001];

void init() {
  for (int i = 0; i <= n; i++) {
    g[i].parent = i;
    g[i].node = 1LL;
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
  cin >> n;
  init();
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    e.push_back({w, {u, v}});
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < e.size(); i++) {
    int left = ufind(e[i].second.first);
    int right = ufind(e[i].second.second);
    ans += g[left].node * g[right].node * e[i].first;
    umerge(left, right);
  }
  cout << ans << endl;
}