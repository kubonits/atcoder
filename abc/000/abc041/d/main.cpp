#include <iostream>

using namespace std;
typedef long long ll;
ll dp[(1 << 16)];

int main() {
  int n, m, x, y, g[16][16] = {}, flag;
  cin >> n >> m;
  dp[0] = 1LL;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    g[x][y] = 1;
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        flag = 1;
        for (int k = 0; k < n; k++) {
          if ((i & (1 << k)) && g[k][j] == 1) {
            flag = 0;
          }
        }
        if (flag) {
          dp[i + (1 << j)] += dp[i];
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}