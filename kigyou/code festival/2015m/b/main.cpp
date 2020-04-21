#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int dp[100][100], ans;

int main() {
  int n;
  string s, l, r;
  cin >> n >> s;
  ans = 100;
  for (int i = 0; i <= n; i++) {
    dp[0][i] = i;
    dp[i][0] = i;
  }
  for (int k = 0; k < n; k++) {
    l = s.substr(0, k);
    r = s.substr(k);
    if (l == r) {
      cout << 0 << endl;
      return 0;
    }
    for (int i = 1; i <= l.length(); i++) {
      for (int j = 1; j <= r.length(); j++) {
        dp[i][j] = 100;
      }
    }
    for (int i = 0; i < l.length(); i++) {
      for (int j = 0; j < r.length(); j++) {
        dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);
        if (l[i] == r[j]) {
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        }
      }
    }

    ans = min(ans, dp[l.length()][r.length()]);
  }
  cout << ans << endl;
}
