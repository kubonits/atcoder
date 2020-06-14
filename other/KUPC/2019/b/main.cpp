#include <algorithm>
#include <iostream>
using namespace std;

struct unionfind {
  int parent;
  int v;
  int w;
};
unionfind g[100];
int dfs(int x) {
  if (g[x].parent == x) {
    return x;
  } else {
    return g[x].parent = dfs(g[x].parent);
  }
}

void merge(int x, int y) {
  if (x > y) {
    int temp = x;
    x = y;
    y = temp;
  }
  g[y].parent = x;
  g[x].v += g[y].v;
  g[x].w += g[y].w;
}

int main() {
  int n, m, W, w, v, a, b;
  int dp[10001] = {};
  cin >> n >> m >> W;
  for (int i = 0; i < n; i++) {
    cin >> w >> v;
    g[i].parent = i;
    g[i].v = v;
    g[i].w = w;
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    a = dfs(a);
    b = dfs(b);
    if (a != b) {
      merge(a, b);
    }
  }
  for (int i = 0; i < n; i++) {
    if (dfs(i) == i) {
      for (int j = W; j - g[i].w >= 0; j--) {
        dp[j] = max(dp[j], dp[j - g[i].w] + g[i].v);
      }
    }
  }
  cout << dp[W] << endl;
}