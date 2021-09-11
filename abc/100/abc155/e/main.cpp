//解説AC
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n, dp[1000005][2];
int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  s += "0";
  n = s.length();

  for (int i = 0; i <= n; i++) {
    dp[i][0] = dp[i][1] = 1000000000;
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      int x = s[i] - '0';
      x += j;
      for (int a = 0; a < 10; a++) {
        int ni = i + 1, nj = 0;
        int b = a - x;
        if (b < 0) {
          nj = 1;
          b += 10;
        }
        dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b);
      }
    }
  }
  cout << min(dp[n][0], dp[n][1] + 1) << endl;
}