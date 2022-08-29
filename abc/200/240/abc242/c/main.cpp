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
  int n;
  cin >> n;
  vector<vector<ll> > dp(n + 1, vector<ll>(10));
  for (int i = 1; i <= 9; i++) {
    dp[0][i] = 1LL;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 9; j++) {
      if (j + 1 < 10) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= MOD2;
      }
      if (j - 1 > 0) {
        dp[i + 1][j - 1] += dp[i][j];
        dp[i + 1][j - 1] %= MOD2;
      }
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD2;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= 9; i++) {
    ans += dp[n - 1][i];
    ans %= MOD2;
  }
  cout << ans << endl;
}
