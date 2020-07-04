#include <algorithm>
#include <cmath>
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
int main() {
  ll n, a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<vector<ll> > dp(c + 10);
  for (int i = 0; i < c + 10; i++) {
    dp[i].resize(d + 10);
  }
  dp[a][b] = 1;
  for (ll i = a; i < c; i++) {
    dp[i + 1][b] = dp[i][b] * b;
    dp[i + 1][b] %= MOD;
  }
  for (ll i = b; i < d; i++) {
    dp[a][i + 1] = dp[a][i] * a;
    dp[a][i + 1] %= MOD;
  }
  for (ll i = a + 1; i <= c; i++) {
    for (ll j = b + 1; j <= d; j++) {
      dp[i][j] = dp[i - 1][j] * j + dp[i][j - 1] * i -
                 dp[i - 1][j - 1] * (i - 1) * (j - 1) + MOD * (ll)10000000;
      dp[i][j] %= MOD;
    }
  }
  cout << dp[c][d] << endl;
}