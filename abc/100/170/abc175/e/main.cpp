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

int main() {
  int r, c, x, y, k;
  cin >> r >> c >> k;
  vector<vector<ll> > v(r);
  vector<vector<vector<ll> > > dp(r);
  for (int i = 0; i < r; i++) {
    v[i].resize(c);
    dp[i].resize(c);
    for (int j = 0; j < c; j++) {
      dp[i][j].resize(4);
      dp[i][j] = {0, 0, 0, 0};
      v[i][j] = 0;
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    x--;
    y--;
    cin >> v[x][y];
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int l = 0; l < 3; l++) {
        dp[i][j][l + 1] = max(dp[i][j][l + 1], dp[i][j][l]);
      }
      if (j != c - 1) {
        for (int l = 0; l < 3; l++) {
          dp[i][j + 1][l + 1] = max(dp[i][j + 1][l + 1], dp[i][j][l] + v[i][j]);
        }
        for (int l = 0; l < 4; l++) {
          dp[i][j + 1][l] = max(dp[i][j + 1][l], dp[i][j][l]);
        }
      }
      if (i != r - 1) {
        dp[i + 1][j][0] =
            max(dp[i + 1][j][0], max(dp[i][j][3], dp[i][j][2] + v[i][j]));
      }
    }
  }
  cout << max(dp[r - 1][c - 1][3], dp[r - 1][c - 1][2] + v[r - 1][c - 1])
       << endl;
}