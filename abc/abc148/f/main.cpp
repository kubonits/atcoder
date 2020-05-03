#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, u, v, disu[100001], disv[100001];
vector<int> G[100001];

void dfsu(int x, int y, int d) {
  disu[x] = d;
  for (int i = 0; i < G[x].size(); i++) {
    if (G[x][i] != y) {
      dfsu(G[x][i], x, d + 1);
    }
  }
}

void dfsv(int x, int y, int d) {
  disv[x] = d;
  for (int i = 0; i < G[x].size(); i++) {
    if (G[x][i] != y) {
      dfsv(G[x][i], x, d + 1);
    }
  }
}

int main() {
  int ans = 0;
  cin >> n >> u >> v;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfsu(u, -1, 0);
  dfsv(v, -1, 0);
  for (int i = 1; i <= n; i++) {
    if (disu[i] < disv[i]) {
      ans = max(ans, disv[i] - 1);
    }
  }
  cout << ans << endl;
}