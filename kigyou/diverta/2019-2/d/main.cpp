#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

ll dp[25000000];

int main() {
  ll n, g[2], s[2], b[2], ans = 0LL, a = 0LL;
  scanf("%lld", &n);
  for (int i = 0; i < 2; i++) {
    scanf("%lld%lld%lld", &g[i], &s[i], &b[i]);
  }
  for (int i = 0; i <= n; i++) {
    a = max(a, dp[i]);
    if (i + g[0] <= n) {
      dp[i + g[0]] = max(dp[i + g[0]], dp[i] + g[1] - g[0]);
    }
    if (i + s[0] <= n) {
      dp[i + s[0]] = max(dp[i + s[0]], dp[i] + s[1] - s[0]);
    }
    if (i + b[0] <= n) {
      dp[i + b[0]] = max(dp[i + b[0]], dp[i] + b[1] - b[0]);
    }
  }
  a = max(a, dp[n]) + n;
  for (int i = 0; i <= n; i++) {
    dp[i] = 0LL;
  }
  for (ll i = 0; i <= a; i++) {
    ans = max(ans, dp[i] + a);
    if (i + g[1] <= a) {
      dp[i + g[1]] = max(dp[i + g[1]], dp[i] + g[0] - g[1]);
    }
    if (i + s[1] <= a) {
      dp[i + s[1]] = max(dp[i + s[1]], dp[i] + s[0] - s[1]);
    }
    if (i + b[1] <= a) {
      dp[i + b[1]] = max(dp[i + b[1]], dp[i] + b[0] - b[1]);
    }
  }
  printf("%lld\n", ans);
}