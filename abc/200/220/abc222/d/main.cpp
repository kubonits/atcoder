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
  int n;
  cin >> n;
  ll ans = 0LL;
  vector<int> a(n), b(n), cmin(n), cmax(n), sum(3001);
  vector<vector<ll> > dp(n + 1, vector<ll>(3001));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cmin[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    cmax[i] = b[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    sum[0] = dp[i][0];
    for (int j = 1; j <= 3000; j++) {
      sum[j] = sum[j - 1] + dp[i][j];
      sum[j] %= MOD;
    }
    for (int j = 0; j <= 3000; j++) {
      if (j >= a[i] && j <= b[i]) {
        dp[i + 1][j] = sum[j];
      }
    }
  }
  for (int i = 0; i <= 3000; i++) {
    ans += dp[n][i];
    ans %= MOD;
  }
  cout << ans << endl;
}
