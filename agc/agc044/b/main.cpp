#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int p[250001], n;
int g[500][500];
int visited[250000];

int main() {
  int ans = 0;
  queue<pair<int, int> > q;
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = 1000;
      g[i][j] = min(g[i][j], i);
      g[i][j] = min(g[i][j], j);
      g[i][j] = min(g[i][j], n - 1 - i);
      g[i][j] = min(g[i][j], n - 1 - j);
    }
  }
  for (int i = 0; i < n * n; i++) {
    int x = p[i] / n;
    int y = p[i] % n;
    visited[p[i]] = 1;
    if (x != 0) {
      g[x][y] = min(g[x][y], g[x - 1][y] + 1 - visited[x * n + y - n]);
    }
    if (x != n - 1) {
      g[x][y] = min(g[x][y], g[x + 1][y] + 1 - visited[x * n + y + n]);
    }
    if (y != 0) {
      g[x][y] = min(g[x][y], g[x][y - 1] + 1 - visited[x * n + y - 1]);
    }
    if (y != n - 1) {
      g[x][y] = min(g[x][y], g[x][y + 1] + 1 - visited[x * n + y + 1]);
    }
    ans += g[x][y];
    if (x != 0 && g[x - 1][y] > g[x][y]) {
      g[x - 1][y] = g[x][y];
      q.push({x - 1, y});
    }
    if (x != n - 1 && g[x + 1][y] > g[x][y]) {
      g[x + 1][y] = g[x][y];
      q.push({x + 1, y});
    }
    if (y != 0 && g[x][y - 1] > g[x][y]) {
      g[x][y - 1] = g[x][y];
      q.push({x, y - 1});
    }
    if (y != n - 1 && g[x][y + 1] > g[x][y]) {
      g[x][y + 1] = g[x][y];
      q.push({x, y + 1});
    }
    while (!q.empty()) {
      x = q.front().first;
      y = q.front().second;
      q.pop();
      if (x != 0 && g[x - 1][y] > g[x][y] + 1 - visited[x * n + y]) {
        g[x - 1][y] = g[x][y] + 1 - visited[x * n + y];
        q.push({x - 1, y});
      }
      if (x != n - 1 && g[x + 1][y] > g[x][y] + 1 - visited[x * n + y]) {
        g[x + 1][y] = g[x][y] + 1 - visited[x * n + y];
        q.push({x + 1, y});
      }
      if (y != 0 && g[x][y - 1] > g[x][y] + 1 - visited[x * n + y]) {
        g[x][y - 1] = g[x][y] + 1 - visited[x * n + y];
        q.push({x, y - 1});
      }
      if (y != n - 1 && g[x][y + 1] > g[x][y] + 1 - visited[x * n + y]) {
        g[x][y + 1] = g[x][y] + 1 - visited[x * n + y];
        q.push({x, y + 1});
      }
    }
  }
  cout << ans << endl;
}