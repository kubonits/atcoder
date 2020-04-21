#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int dp[20010], h, n, a[1000], b[1000], ans = 500000000;
  scanf("%d%d", &h, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int i = 0; i <= 20000; i++) {
    dp[i] = 500000000;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 20000 - a[i]; j++) {
      dp[j + a[i]] = min(dp[j + a[i]], dp[j] + b[i]);
    }
  }
  for (int i = h; i <= 20000; i++) {
    ans = min(ans, dp[i]);
  }
  printf("%d\n", ans);
}