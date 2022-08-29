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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  vector<vector<vector<vector<int> > > > dp(
      n + 1, vector<vector<vector<int> > >(
                 n + 1, vector<vector<int> >(n + 1, vector<int>(n + 1))));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[0][0][i][0] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 1; k <= n; k++) {
        for (int l = 0; l < k; l++) {
          dp[i + 1][j][k][l] += dp[i][j][k][l];
          dp[i + 1][j][k][l] %= MOD2;
          dp[i + 1][j + 1][k][(l + a[i]) % k] += dp[i][j][k][l];
          dp[i + 1][j + 1][k][(l + a[i]) % k] %= MOD2;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += dp[n][i][i][0];
    ans %= MOD2;
  }
  cout << ans << endl;
}
