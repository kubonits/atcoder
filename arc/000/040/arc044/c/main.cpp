#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, dp[50][50] = {};
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = 0;
    } else {
      dp[i][i + 1] = 2;
    }
  }
  for (int k = 1; k < n; k++) {
    for (int i = 0; i + k < n; i++) {
      if (s[i] == s[i + k]) {
        dp[i][i + k] = dp[i + 1][i + k - 1];
      } else {
        dp[i][i + k] = min(dp[i + 1][i + k], dp[i][i + k - 1]) + 1;
        dp[i][i + k] = min(dp[i][i + k], dp[i + 1][i + k - 1] + 2);
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}