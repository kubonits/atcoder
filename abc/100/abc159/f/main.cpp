#include <iostream>
#define MOD 998244353
using namespace std;
long long n, s, a[3000], dp[3001][3001][3];
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      dp[i + 1][j][0] += dp[i][j][0];
      dp[i + 1][j][0] %= MOD;
      dp[i + 1][j][1] += (dp[i][j][0] + dp[i][j][1]) % MOD;
      dp[i + 1][j][1] %= MOD;
      dp[i + 1][j][2] += (dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) % MOD;
      dp[i + 1][j][2] %= MOD;
      if (j + a[i] <= s) {
        dp[i + 1][j + a[i]][1] += (dp[i][j][0] + dp[i][j][1]) % MOD;
        dp[i + 1][j + a[i]][1] %= MOD;
        dp[i + 1][j + a[i]][2] += (dp[i][j][0] + dp[i][j][1]) % MOD;
        dp[i + 1][j + a[i]][2] %= MOD;
      }
    }
  }
  cout << dp[n][s][2] << endl;
}