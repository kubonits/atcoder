#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int dp[5001][5001];
int main() {
  string s, t;
  int ans = 0;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < s.length(); j++) {
      dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
  }
  cout << dp[s.length()][s.length()] + 1 << endl;
}