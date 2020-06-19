#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001], c;

int dfs(int x, int y, int z) {
  int res = 0;
  for (int i = 0; i < v[x].size(); i++) {
    if (y != v[x][i]) {
      res += dfs(v[x][i], x, z | c[x]);
    }
  }
  if (z && res == 2 || c[x] && res == 0) {
    res++;
  }
  return res;
}

int main() {
  int n, m, a, b, d;
  cin >> n >> m;
  c.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    c[i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 0; i < m; i++) {
    cin >> d;
    c[d] = 1;
  }
  if (dfs(1, -1, 0) <= 2) {
    cout << "Yes" << endl;
  } else {
    cout << "trumpet" << endl;
  }
}