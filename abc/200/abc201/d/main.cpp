#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>
int dp[2001][2001];
int main() {
  int h, w;
  string s[2000];
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  dp[h][w] = 0;
  for (int i = w - 2; i >= 0; i--) {
    if ((i + h + 1) % 2) {
      dp[h][i + 1] = dp[h][i + 2] + (s[h - 1][i + 1] == '+' ? -1 : 1);
    } else {
      dp[h][i + 1] = dp[h][i + 2] + (s[h - 1][i + 1] == '+' ? 1 : -1);
    }
  }
  for (int i = h - 2; i >= 0; i--) {
    if ((w + i + 1) % 2) {
      dp[i + 1][w] = dp[i + 2][w] + (s[i + 1][w - 1] == '+' ? -1 : 1);
    } else {
      dp[i + 1][w] = dp[i + 2][w] + (s[i + 1][w - 1] == '+' ? 1 : -1);
    }
  }
  for (int i = h - 2; i >= 0; i--) {
    for (int j = w - 2; j >= 0; j--) {
      if ((i + j) % 2) {
        dp[i + 1][j + 1] =
            min(dp[i + 2][j + 1] - (s[i + 1][j] == '+' ? 1 : -1),
                dp[i + 1][j + 2] - (s[i][j + 1] == '+' ? 1 : -1));
      } else {
        dp[i + 1][j + 1] =
            max(dp[i + 2][j + 1] + (s[i + 1][j] == '+' ? 1 : -1),
                dp[i + 1][j + 2] + (s[i][j + 1] == '+' ? 1 : -1));
      }
    }
  }
  if (!dp[1][1]) {
    cout << "Draw" << endl;
  } else {
    cout << (dp[1][1] > 0 ? "Takahashi" : "Aoki") << endl;
  }
}
