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
  cin >> n;
  vector<ll> a(n), dp(n + 1);
  ll ans = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1000LL;
  }
  dp[n] = 1000LL;
  for (int i = 0; i < n; i++) {
    ll x = 0LL;
    for (int j = 0; j <= i; j++) {
      x = max(x, dp[j]);
    }
    for (int j = i + 1; j <= n; j++) {
      dp[j] = max(dp[j], x % a[i] + x / a[i] * a[j - 1]);
    }
  }
  for (int i = 0; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}