#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

vector<int> f[100001], b[100001];
int g[100010], s[100010];

void dfs(int x, int y) {
  g[x] = y;
  s[y]++;
  for (int i = 0; i < f[x].size(); i++) {
    if (g[f[x][i]] == 0) {
      dfs(f[x][i], y);
    }
  }
}

int main() {
  int n, m, k, c, d;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &c, &d);
    f[c].push_back(d);
    f[d].push_back(c);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &c, &d);
    b[c].push_back(d);
    b[d].push_back(c);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i] == 0) {
      dfs(i, i);
    }
  }
  for (int i = 1; i <= n; i++) {
    int ans = s[g[i]];
    ans -= f[i].size();
    for (int j = 0; j < b[i].size(); j++) {
      if (g[i] == g[b[i][j]]) {
        ans--;
      }
    }
    ans--;
    printf("%d ", ans);
  }
  printf("\n");
}