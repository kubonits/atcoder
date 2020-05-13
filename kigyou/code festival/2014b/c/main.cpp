#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, a[3][26] = {};
  string s[3];
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  n = s[0].length();
  vector<int> dp[27];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      a[j][s[j][i] - 'A']++;
    }
  }
  for (int i = 0; i < 27; i++) {
    dp[i].resize(n + 1);
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < 26; i++) {
    for (int j = max(0, a[2][i] - a[1][i]); j <= min(a[0][i], a[2][i]); j++) {
      for (int k = n / 2; k - j >= 0; k--) {
        if (dp[i][k - j]) {
          dp[i + 1][k] = 1;
        }
      }
    }
  }
  if (dp[26][n / 2] == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}