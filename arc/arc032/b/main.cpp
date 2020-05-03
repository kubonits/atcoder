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
  int a, b, cnt = 0;
  cin >> n >> m;
  init();
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a = find(a);
    b = find(b);
    if (a != b) {
      merge(a, b);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].parent == i) {
      cnt++;
    }
  }
  cout << cnt - 1 << endl;
}