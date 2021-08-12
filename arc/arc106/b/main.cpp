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
unionfind g[200010];

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
  int c, d;
  cin >> n >> m;
  vector<ll> a(n), b(n), sum(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sum[i] = 0;
  }
  init();
  for (int i = 0; i < m; i++) {
    cin >> c >> d;
    c--;
    d--;
    c = ufind(c);
    d = ufind(d);
    if (c != d) {
      umerge(c, d);
    }
  }
  for (int i = 0; i < n; i++) {
    ufind(i);
    sum[g[i].parent] += a[i] - b[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}