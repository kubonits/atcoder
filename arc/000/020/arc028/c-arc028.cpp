#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int n, p[100000];
pair<int, int> dp[100000];
vector<pair<int, int> > g[100000];

int dfs(int x, int y) {
  int res = 1;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i].first != y) {
      dp[g[x][i].second].second = x;
      dp[g[x][i].second].first = dfs(g[x][i].first, x);
      res += dp[g[x][i].second].first;
    }
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &p[i]);
    g[i + 1].push_back({p[i], i});
    g[p[i]].push_back({i + 1, i});
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    int ans = 0;
    int sum = 0;
    for (int j = 0; j < g[i].size(); j++) {
      if (dp[g[i][j].second].second == i) {
        ans = max(ans, dp[g[i][j].second].first);
        sum += dp[g[i][j].second].first;
      }
    }
    ans = max(ans, n - 1 - sum);
    printf("%d\n", ans);
  }
}