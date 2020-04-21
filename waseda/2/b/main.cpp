#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, dp[110];
  string s;
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1000;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= 3; j++) {
      if (s[i + j] == 'X') {
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      } else {
        dp[i + j] = min(dp[i + j], dp[i]);
      }
    }
  }
  cout << dp[n - 1] << endl;
}