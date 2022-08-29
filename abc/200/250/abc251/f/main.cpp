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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

vector<vector<int> > G;
vector<pair<int, int> > t1, t2;
vector<int> visited;
void dfs(int x, int y) {
  visited[x] = 1;
  for (int i = 0; i < G[x].size(); i++) {
    if (visited[G[x][i]] == 0) {
      cout << x << " " << G[x][i] << endl;
      dfs(G[x][i], x);
    }
  }
}
int main() {
  int n, m, u, v;
  cin >> n >> m;
  visited.resize(n + 1);
  G.resize(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, -1);
  for (int i = 0; i <= n; i++) {
    visited[i] = 0;
  }
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    visited[x] = 1;
    for (int i = 0; i < G[x].size(); i++) {
      if (visited[G[x][i]] == 0) {
        cout << x << " " << G[x][i] << endl;
        visited[G[x][i]] = 1;
        q.push(G[x][i]);
      }
    }
  }
}
