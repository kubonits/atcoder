#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
int dp[5001][(1 << 10)][11];

int main() {
  int n, m, y, z, p, ans = 0;
  map<string, pii> ma;
  string c, s;
  cin >> n >> m >> y >> z;
  for (int i = 0; i < m; i++) {
    cin >> c >> p;
    ma.insert({c, {p, i + 1}});
  }
  cin >> s;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < (1 << m); j++) {
      for (int k = 0; k <= m; k++) {
        dp[i][j][k] = -1000000000;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    string t = s.substr(i, 1);
    p = ma[t].second;
    for (int j = 0; j < (1 << m); j++) {
      for (int k = 0; k <= m; k++) {
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
        if (k == p) {
          dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + ma[t].first + y);
        } else {
          dp[i + 1][(j | (1 << (p - 1)))][p] = max(
              dp[i + 1][(j | (1 << (p - 1)))][p], dp[i][j][k] + ma[t].first);
        }
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    dp[n][(1 << m) - 1][i] += z;
  }
  for (int i = 0; i < (1 << m); i++) {
    for (int j = 0; j <= m; j++) {
      ans = max(ans, dp[n][i][j]);
    }
  }
  cout << ans << endl;
}