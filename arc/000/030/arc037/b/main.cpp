#include <iostream>
using namespace std;

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
  int v, u, ans = 0;
  cin >> n >> m;
  init();
  for (int i = 0; i < m; i++) {
    cin >> v >> u;
    v = find(v);
    u = find(u);
    if (u == v) {
      g[u].edge++;
    } else {
      merge(u, v);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].parent == i && g[i].node - g[i].edge == 1) {
      ans++;
    }
  }
  cout << ans << endl;
}