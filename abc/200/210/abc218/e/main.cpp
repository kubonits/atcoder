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
  ll ans = 0LL, a, b, c;
  vector<pair<ll, pair<int, int> > > v;
  cin >> n >> m;
  init();
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    v.push_back({c, {a, b}});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    a = ufind(v[i].second.first);
    b = ufind(v[i].second.second);
    if (a != b) {
      umerge(a, b);
    } else if (v[i].first > 0LL) {
      ans += v[i].first;
    }
  }
  cout << ans << endl;
}
