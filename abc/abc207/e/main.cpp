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
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<ll> a(n);
  vector<vector<ll> > dp(n + 1), sum(n + 1);
  vector<vector<set<ll> > > s(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i].resize(n + 1);
    sum[i].resize(n + 1);
    s[i].resize(n + 1);
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < n; i++) {
      sum[i + 1][j] = (sum[i][j] + a[i]) % j;
      s[j][sum[i + 1][j]].insert(i);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0LL;
    }
  }
  dp[1][1] = 1LL;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (dp[i][j]) {
        dp[i][j] %= MOD;
        set<ll>::iterator it = s[j][sum[i][j]].upper_bound(i - 1);
        if (it != s[j][sum[i][j]].end()) {
          dp[(*it) + 1][j] += dp[i][j];
        }
        it = s[j + 1][sum[i][j + 1]].upper_bound(i - 1);
        if (it != s[j + 1][sum[i][j + 1]].end()) {
          dp[(*it) + 1][j + 1] += dp[i][j];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += dp[n][i];
    ans %= MOD;
  }
  cout << ans << endl;
}