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
  int n, k;
  ll ans = 0LL;
  cin >> n >> k;
  vector<ll> a(n);

  ans = 0LL;
  vector<ll> maxi(n + 1);
  vector<vector<ll> > dp(n + 1, vector<ll>(n + 1)),
      dp2(n + 1, vector<ll>(n + 1));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < n; j++) {
    dp[0][j + 1] = dp2[0][j + 1] = maxi[max(0, j + 1 - k)] + a[j];
    ans = max(ans, dp[0][j + 1]);
    maxi[j + 1] = max(maxi[j], dp[0][j + 1]);
    for (int i = 1; i <= j; i++) {
      dp[i][j + 1] = dp2[max(0, j + 1 - k)][i] + a[j];
      dp2[i][j + 1] = max(dp2[i - 1][j + 1], dp[i][j + 1]);
      ans = max(ans, dp[i][j + 1]);
      maxi[j + 1] = max(maxi[j + 1], dp[i][j + 1]);
    }
  }
  cout << ans << endl;
}
