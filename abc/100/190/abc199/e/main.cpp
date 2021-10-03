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
  int n, m, flag;
  cin >> n >> m;
  vector<ll> dp(1 << n);
  vector<int> x(m), y(m), z(m), v(n), sum(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  dp[0] = 1LL;
  sum[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    flag = 1;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        v[j] = 1;
      } else {
        v[j] = 0;
      }
      sum[j + 1] = sum[j] + v[j];
    }
    for (int j = 0; j < m; j++) {
      if (sum[n] == x[j] && sum[y[j]] > z[j]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          dp[i] += dp[i ^ (1 << j)];
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}
