#include <cstdio>
using namespace std;
typedef long long ll;
ll dp[(1 << 13)][1301];
ll ans;

int main() {
  int n, a, b, x[13], sum;
  scanf("%d%d%d", &n, &a, &b);
  while (n || a || b) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
      sum += x[i];
    }
    for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0) {
          for (int k = 1300; k >= 0; k--) {
            dp[i + (1 << j)][k] += dp[i][k];
            if (k + x[j] <= 1300) {
              dp[i + (1 << j)][k + x[j]] += dp[i][k];
            }
          }
        }
      }
    }
    ans = 0LL;
    for (int i = 0; i < n; i++) {
    }
  }
}