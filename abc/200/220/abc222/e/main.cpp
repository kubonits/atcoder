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
#define MOD 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int n, m, k;
vector<pair<int, int> > g[1000];
vector<int> a;
vector<set<int> > s;

void dfs(int x, int y, vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    s[v[i]].insert(x);
  }
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i].first != y) {
      v.push_back(g[x][i].second);
      dfs(g[x][i].first, x, v);
      v.pop_back();
    }
  }
}

int main() {
  int u, v, sum = 0;
  cin >> n >> m >> k;
  vector<int> num(n - 1);
  a.resize(m);
  s.resize(n);
  vector<vector<int> > dp(n, vector<int>(100001));
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  vector<int> b;
  dfs(0, -1, b);
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (s[j].find(a[i]) != s[j].end() && s[j].find(a[i + 1]) == s[j].end() ||
          s[j].find(a[i]) == s[j].end() && s[j].find(a[i + 1]) != s[j].end()) {
        num[j]++;
      }
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < n - 1; i++) {
    sum += num[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j <= i * m; j++) {
      dp[i + 1][j + num[i]] += dp[i][j];
      dp[i + 1][j + num[i]] %= MOD;
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
    }
  }
  if (k < 0) {
    k *= -1;
  }
  if ((sum + k) % 2) {
    cout << 0 << endl;
    return 0;
  }
  cout << dp[n - 1][(sum + k) / 2] << endl;
}
