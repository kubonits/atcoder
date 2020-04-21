#include <iostream>
#include <string>
using namespace std;

int h, w, dp[100][100];
string s[100];

int dfs(int x, int y) {
  if (x < h - 1 && y < w - 1) {
    if (dp[x + 1][y + 1] == -1) {
      dp[x][y] = 1;
      return 1;
    }
    if (s[x + 1][y + 1] == '.' && dp[x + 1][y + 1] == 0 &&
        dfs(x + 1, y + 1) == 0) {
      dp[x][y] = 1;
      return 1;
    }
  }
  if (x < h - 1) {
    if (dp[x + 1][y] == -1) {
      dp[x][y] = 1;
      return 1;
    }
    if (s[x + 1][y] == '.' && dp[x + 1][y] == 0 && dfs(x + 1, y) == 0) {
      dp[x][y] = 1;
      return 1;
    }
  }
  if (y < w - 1) {
    if (dp[x][y + 1] == -1) {
      dp[x][y] = 1;
      return 1;
    }
    if (s[x][y + 1] == '.' && dp[x][y + 1] == 0 && dfs(x, y + 1) == 0) {
      dp[x][y] = 1;
      return 1;
    }
  }
  dp[x][y] = -1;
  return 0;
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  dfs(0, 0);
  if (dp[0][0] == 1) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}