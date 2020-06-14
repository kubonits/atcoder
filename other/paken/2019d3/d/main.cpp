#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n, dp[1000][3] = {};
  string s[5], t = "RBW";
  cin >> n;
  for (int i = 0; i < 5; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 5; i++) {
    if (s[i][0] != 'R') {
      dp[1][0]++;
    }
    if (s[i][0] != 'B') {
      dp[1][1]++;
    }
    if (s[i][0] != 'W') {
      dp[1][2]++;
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      dp[i][j] = 10000000;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int cnt = 0;
      for (int k = 0; k < 5; k++) {
        if (s[k][i] != t[j]) {
          cnt++;
        }
      }
      for (int k = 0; k < 3; k++) {
        if (j != k) {
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + cnt);
        }
      }
    }
  }
  cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}