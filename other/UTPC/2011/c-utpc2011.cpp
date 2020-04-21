#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, dp[20][20] = {}, ans = 0;
  string s;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'w') {
      dp[i][i] = 100;
      ans = 100;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; i + j < n; j++) {
      dp[j][j + i] = max(dp[j + 1][i + j], dp[j][i + j - 1]);
      if (s[j] == 'i' && s[i + j] == 'i' || s[j] == 'w' && s[i + j] == 'w' ||
          s[j] == '(' && s[i + j] == ')' || s[j] == ')' && s[i + j] == '(' ||
          s[j] == '{' && s[i + j] == '}' || s[j] == '}' && s[i + j] == '{' ||
          s[j] == '[' && s[i + j] == ']' || s[j] == ']' && s[i + j] == '[') {
        dp[j][i + j] = max(dp[j][i + j], dp[j + 1][i + j - 1] + 2);
      }
      ans = max(ans, dp[j][i + j]);
    }
  }
  printf("%d\n", ans - 99);
}