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
vector<set<int> > s;

int n;
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

void dfs(int x) {
  int y = *s[x].begin();
  s[x].erase(y);
  s[y].erase(x);
  if (s[y].size() == 1) {
    dfs(y);
  }
}

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n = n >> 1;
  }
  return res;
}

int main() {
  int m, a, b;
  set<int> ans;
  cin >> n >> m;
  s.resize(n);
  if (n != m) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    s[a].insert(b);
    s[b].insert(a);
  }
  for (int i = 0; i < n; i++) {
    if (s[i].size() == 1) {
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i].size() != 2 && s[i].size() != 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  init();
  for (int i = 0; i < n; i++) {
    for (auto &&num : s[i]) {
      int x = ufind(i);
      int y = ufind(num);
      if (x != y) {
        umerge(x, y);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i].size() == 2) {
      ans.insert(ufind(i));
    }
  }
  cout << mod_pow(2, ans.size(), MOD) << endl;
}
