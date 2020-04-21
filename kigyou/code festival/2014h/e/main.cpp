#include <iostream>
using namespace std;

int main() {
  int n, r[3000], dp[3000][2] = {}, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r[i];
    dp[i][0] = dp[i][1] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (r[i] > r[j]) {
        dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        ans = max(ans, dp[i][1]);
      } else if (r[i] < r[j]) {
        dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        ans = max(ans, dp[i][0]);
      }
    }
  }
  if (ans < 3) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
}