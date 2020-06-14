#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll dp[3001][3001];
int main() {
  int n, s;
  int a[3000];
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      dp[i + 1][j] = dp[i][j] * 2LL % MOD;
      if (j - a[i] >= 0) {
        dp[i + 1][j] += dp[i][j - a[i]];
      }
      dp[i + 1][j] %= MOD;
    }
  }
  cout << dp[n][s] << endl;
}