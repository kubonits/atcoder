#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int> > g[5001];
int dp[5000][5001];
int child[5000];
void dfs(int x, int y, int z) {
  for (int i = 1; i <= 5000; i++)
    for (int i = 0; i < g[x].size(); i++) {
      if (g[x][i].first != y) {
        if (z >= g[x][i].second) {
          res++;
        }
        res += dfs(g[x][i].first, x, min(z, g[x][i].second));
      }
    }
}

int main() {
  int n, p, h, ans = 0;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> p >> h;
    g[i].push_back({p, h});
    g[p].push_back({i, h});
  }
  for (int i = 0; i < g[0].size(); i++) {
    dfs(g[0][i].first, 0, g[0][i].second);
    for (int j = 5000; j >= 0; j++) {
      if (dp[g[0][i].first][j] <= g[0][i].second) {
        ans += j + 1;
        break;
      }
    }
  }
  cout << ans << endl;
}