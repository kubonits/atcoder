#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
int dp[100001], x[100001];
int main() {
  int n, l, a, t[3], ans = 2000000000;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a;
    x[a] = 1;
  }
  cin >> t[0] >> t[1] >> t[2];
  for (int i = 1; i <= l; i++) {
    dp[i] = 2000000000;
  }
  for (int i = 0; i < l; i++) {
    if (i + 1 <= l && x[i + 1] == 0) {
      dp[i + 1] = min(dp[i + 1], dp[i] + t[0]);
    } else if (i + 1 <= l) {
      dp[i + 1] = min(dp[i + 1], dp[i] + t[0] + t[2]);
    }
    if (i + 2 <= l && x[i + 2] == 0) {
      dp[i + 2] = min(dp[i + 2], dp[i] + t[0] + t[1]);
    } else if (i + 2 <= l) {
      dp[i + 2] = min(dp[i + 2], dp[i] + t[0] + t[1] + t[2]);
    }
    if (i + 4 <= l && x[i + 4] == 0) {
      dp[i + 4] = min(dp[i + 4], dp[i] + t[0] + 3 * t[1]);
    } else if (i + 4 <= l) {
      dp[i + 4] = min(dp[i + 4], dp[i] + t[0] + 3 * t[1] + t[2]);
    }
    if (i + 1 == l) {
      ans = min(ans, dp[i] + t[0] / 2 + t[1] / 2);
      ans = min(ans, dp[i] + t[0]);
    }
    if (i + 2 == l) {
      ans = min(ans, dp[i] + t[0] + t[1]);
      ans = min(ans, dp[i] + t[0] / 2 + t[1] / 2 * 3);
    }
    if (i + 3 == l) {
      ans = min(ans, dp[i] + t[0] / 2 + t[1] / 2 * 5);
    }
  }
  ans = min(ans, dp[l]);
  cout << ans << endl;
}