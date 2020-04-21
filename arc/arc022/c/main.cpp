#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, dis[100001];
vector<int> v[100001];

void dfs(int x, int y) {
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] != y) {
      dis[v[x][i]] = dis[x] + 1;
      dfs(v[x][i], x);
    }
  }
}

int main() {
  int a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1, -1);
  a = 0;
  b = 0;
  for (int i = 0; i <= n; i++) {
    if (a < dis[i]) {
      b = i;
      a = dis[i];
    }
  }
  cout << b << " ";
  dfs(b, -1);
  a = 0;
  b = 0;
  for (int i = 0; i <= n; i++) {
    if (a < dis[i]) {
      b = i;
      a = dis[i];
    }
  }
  cout << b << endl;
}