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

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<ll> > dp(k + 1, vector<ll>(n));
  vector<int> u(m), v(m);
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  dp[0][0] = 1LL;
  for (int i = 0; i < k; i++) {
    ll sum = 0LL;
    for (int j = 0; j < n; j++) {
      sum += dp[i][j];
      sum %= MOD;
    }
    for (int j = 0; j < n; j++) {
      dp[i + 1][j] = (sum + MOD - dp[i][j]) % MOD;
    }
    for (int j = 0; j < m; j++) {
      dp[i + 1][u[j]] += (MOD - dp[i][v[j]]);
      dp[i + 1][v[j]] += (MOD - dp[i][u[j]]);
      dp[i + 1][u[j]] %= MOD;
      dp[i + 1][v[j]] %= MOD;
    }
  }
  cout << dp[k][0] << endl;
}