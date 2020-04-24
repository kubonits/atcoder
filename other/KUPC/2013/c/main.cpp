#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, m, a[100][100], sum[2][102][102] = {}, ans = 0, cnt;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (i) {
        a[i][j] ^= 1;
      }
      if (j != 0 && j != m - 1) {
        a[i][j] ^= 1;
      }
      sum[0][i][j + 1] = sum[0][i][j] + a[i][j];
      sum[1][i][j + 1] = sum[1][i][j] + (a[i][j] ^ 1);
    }
    sum[0][i][m + 1] = sum[0][i][m];
    sum[1][i][m + 1] = sum[1][i][m];
  }
  for (int i = 0; i < n; i++) {
    cnt = 0;
    if (m != 1) {
      for (int j = 0; j < m; j++) {
        cnt = max(cnt, sum[0][i][m] - a[i][j] + (a[i][j] ^ 1));
      }
    } else {
      cnt = a[i][0];
    }
    ans += cnt;
  }
  cout << ans << endl;
}