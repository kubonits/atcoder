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
int dp[301][601][601];
int main() {
  int n, x, y, xx = 0, yy = 0, ans = 500;

  cin >> n >> x >> y;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    xx += a[i];
    yy += b[i];
  }
  if (xx < x || yy < y) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i <= 300; i++) {
    for (int j = 0; j <= 600; j++) {
      for (int k = 0; k <= 600; k++) {
        dp[i][j][k] = 500;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i <= 600; i++) {
      for (int j = 0; j <= 600; j++) {
        dp[k + 1][i][j] = min(dp[k][i][j], dp[k + 1][i][j]);
        dp[k + 1][min(i + a[k], 600)][min(j + b[k], 600)] = min(
            dp[k + 1][min(i + a[k], 600)][min(j + b[k], 600)], dp[k][i][j] + 1);
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = x; j <= 600; j++) {
      for (int k = y; k <= 600; k++) {
        ans = min(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << endl;
}
