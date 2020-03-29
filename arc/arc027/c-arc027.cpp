#include <algorithm>
#include <cstdio>
using namespace std;

int dp[301][601][301];

int main() {
  int n, x, y, t, l, ans = 0;
  scanf("%d%d", &x, &y);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &t, &l);
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k <= y + x; k++) {
        dp[j][k][i + 1] = dp[j][k][i];
      }
    }
    for (int j = 0; j < x; j++) {
      for (int k = 0; k + t <= x + y; k++) {
        dp[j + 1][k + t][i + 1] = max(dp[j + 1][k + t][i + 1], dp[j][k][i] + l);
      }
    }
  }
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= x + y; j++) {
      ans = max(ans, dp[i][j][n]);
    }
  }
  printf("%d\n", ans);
}