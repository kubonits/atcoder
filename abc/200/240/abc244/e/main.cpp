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

int main() {
  int n, m, k, s, x, t;
  cin >> n >> m >> k >> s >> t >> x;
  vector<vector<vector<ll> > > dp(k + 1,
                                  vector<vector<ll> >(n + 1, vector<ll>(2)));
  vector<pair<int, int> > e(m);
  for (int i = 0; i < m; i++) {
    cin >> e[i].first >> e[i].second;
  }
  dp[0][s][0] = 1LL;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      if (e[j].second == x) {
        dp[i + 1][e[j].second][1] += dp[i][e[j].first][0];
        dp[i + 1][e[j].second][1] %= MOD2;
        dp[i + 1][e[j].second][0] += dp[i][e[j].first][1];
        dp[i + 1][e[j].second][0] %= MOD2;
      } else {
        dp[i + 1][e[j].second][1] += dp[i][e[j].first][1];
        dp[i + 1][e[j].second][1] %= MOD2;
        dp[i + 1][e[j].second][0] += dp[i][e[j].first][0];
        dp[i + 1][e[j].second][0] %= MOD2;
      }
      if (e[j].first == x) {
        dp[i + 1][e[j].first][1] += dp[i][e[j].second][0];
        dp[i + 1][e[j].first][1] %= MOD2;
        dp[i + 1][e[j].first][0] += dp[i][e[j].second][1];
        dp[i + 1][e[j].first][0] %= MOD2;
      } else {
        dp[i + 1][e[j].first][1] += dp[i][e[j].second][1];
        dp[i + 1][e[j].first][1] %= MOD2;
        dp[i + 1][e[j].first][0] += dp[i][e[j].second][0];
        dp[i + 1][e[j].first][0] %= MOD2;
      }
    }
  }
  cout << dp[k][t][0] << endl;
}
