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

int find(int x) {
  if (x == g[x].parent) {
    return x;
  }
  int res = find(g[x].parent);
  g[x].node = g[res].node;
  g[x].edge = g[res].edge;
  g[x].parent = res;
  return res;
}

void merge(int x, int y) {
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
  int q, a, u, v;
  cin >> n >> q;
  init();
  for (int i = 0; i < q; i++) {
    cin >> a >> u >> v;
    u = find(u);
    v = find(v);
    if (a == 0 && u != v) {
      merge(u, v);
    } else if (a == 1) {
      cout << (u == v ? 1 : 0) << endl;
    }
  }
}