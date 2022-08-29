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

int n = (1 << 20);

struct unionfind {
  int parent;
  int child;
  int node;
  int edge;
};
unionfind g[(1 << 20)];

void init() {
  for (int i = 0; i <= n; i++) {
    g[i].parent = i;
    g[i].child = i;
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
  if (x < y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  g[x].node += g[y].node;
  g[x].edge += g[y].edge + 1;
  g[y].parent = x;
}

int main() {
  ll q, t, x;
  cin >> q;
  vector<ll> a(1 << 20);
  init();
  for (int i = 0; i < (1 << 20); i++) {
    a[i] = -1;
  }
  for (int i = 0; i < q; i++) {
    cin >> t >> x;
    if (t == 1) {
      ll h = x % (1 << 20);
      while (a[h] != -1) {
        if (h == n - 1) {
          h = 0;
        } else {
          h = ufind(h);
        }
      }
      a[h] = x;
      if (h != n - 1) {
        umerge(ufind(h), ufind((h + 1) % n));
      }
    } else {
      cout << a[x % (1 << 20)] << endl;
    }
  }
}
