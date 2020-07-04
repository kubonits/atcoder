#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll dp[366][366];

int main() {
  int n, m, k;
  ll a[365], ans = -1;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = -1000000000000;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] >= 0) {
        for (int l = 1; l <= k && i + l <= n; l++) {
          dp[i + l][j + 1] = max(dp[i + l][j + 1], dp[i][j] + a[i + l - 1]);
        }
      }
    }
  }
  for (int i = n - k + 1; i <= n; i++) {
    ans = max(dp[i][m], ans);
  }
  cout << (ans > 1 ? ans : -1) << endl;
}