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
unionfind g[100001];

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
  int a, ans = 0;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back({a, i});
  }
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  set<int> s;
  init();
  for (int i = 0; i < n; i++) {
    s.insert(v[i].second);
    if (s.find(v[i].second - 1) != s.end()) {
      umerge(ufind(v[i].second), ufind(v[i].second - 1));
    }
    if (s.find(v[i].second + 1) != s.end()) {
      umerge(ufind(v[i].second), ufind(v[i].second + 1));
    }
    ans = max(ans, v[i].first * g[ufind(v[i].second)].node);
  }
  cout << ans << endl;
}
