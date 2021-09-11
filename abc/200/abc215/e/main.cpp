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
  ll n, ans = 0LL;
  string s;
  cin >> n >> s;
  vector<vector<vector<ll> > > dp(n + 1);
  for (int i = 0; i < n + 1; i++) {
    dp[i].resize(1024);
    for (int j = 0; j < 1024; j++) {
      dp[i][j].resize(11);
    }
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1024; j++) {
      for (int k = 0; k <= 10; k++) {
        dp[i + 1][j][k] += dp[i][j][k];
        int x = j | (1 << (s[i] - 'A'));
        if (k == s[i] - 'A' + 1 || x != j) {
          dp[i + 1][x][s[i] - 'A' + 1] += dp[i][j][k];
          dp[i + 1][x][s[i] - 'A' + 1] %= MOD;
        }
      }
    }
  }
  for (int j = 0; j < 1024; j++) {
    for (int k = 1; k <= 10; k++) {
      ans += dp[n][j][k];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}