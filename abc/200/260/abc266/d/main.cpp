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
  ll ans = 0LL;
  cin >> n;
  vector<int> x(n), t(n);
  vector<ll> a(n);
  vector<vector<ll> > dp(100001, vector<ll>(5));
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> a[i];
  }
  t.push_back(1000000000);
  for (int i = 0; i < 100001; i++) {
    for (int j = 0; j < 5; j++) {
      dp[i][j] = -1000000000000000000;
    }
  }
  dp[0][0] = 0LL;
  int p = 0;
  for (int i = 1; i <= 100000; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = max(0, j - 1); k <= min(4, j + 1); k++) {
        dp[i][j] =
            max(dp[i][j], dp[i - 1][k] + (t[p] == i && x[p] == j ? a[p] : 0LL));
      }
      ans = max(ans, dp[i][j]);
    }
    if (i == t[p]) {
      p++;
    }
  }
  cout << ans << endl;
}
