#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int h, w, a[80][80], b[80][80], dp[80][80][25610];
int main() {
  int ans = 1000000000;
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", &b[i][j]);
      b[i][j] -= a[i][j];
    }
  }
  dp[0][0][12800 + b[0][0]] = 1;
  dp[0][0][12800 - b[0][0]] = 1;
  for (int i = 1; i < h; i++) {
    for (int j = 0; j <= 25600; j++) {
      if (dp[i - 1][0][j]) {
        dp[i][0][j + b[i][0]] = 1;
        dp[i][0][j - b[i][0]] = 1;
      }
    }
  }
  for (int i = 1; i < w; i++) {
    for (int j = 0; j <= 25600; j++) {
      if (dp[0][i - 1][j]) {
        dp[0][i][j + b[0][i]] = 1;
        dp[0][i][j - b[0][i]] = 1;
      }
    }
  }
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      for (int k = 0; k <= 25600; k++) {
        if (dp[i - 1][j][k]) {
          dp[i][j][k + b[i][j]] = 1;
          dp[i][j][k - b[i][j]] = 1;
        }
        if (dp[i][j - 1][k]) {
          dp[i][j][k + b[i][j]] = 1;
          dp[i][j][k - b[i][j]] = 1;
        }
      }
    }
  }
  for (int i = 0; i <= 25600; i++) {
    if (dp[h - 1][w - 1][i]) {
      ans = min(ans, abs(12800 - i));
    }
  }
  printf("%d\n", ans);
}