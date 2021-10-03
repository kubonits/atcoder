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
  ll n, k;
  vector<ll> sum;
  vector<vector<ll> > dp(3);
  cin >> n >> k;
  sum.resize(3 * n + 1);
  for (int i = 0; i < 3; i++) {
    dp[i].resize(3 * n + 1);
  }
  for (int i = 1; i <= n; i++) {
    dp[0][i] = 1LL;
  }
  for (int i = 1; i < 3; i++) {
    for (int j = 0; j < 3 * n; j++) {
      sum[j + 1] = sum[j] + dp[i - 1][j + 1];
    }
    for (int j = 0; j <= 3 * n; j++) {
      dp[i][j] = sum[max(0, j - 1)] - sum[max(0, j - (int)n - 1)];
    }
  }
  for (int i = 0; i < 3 * n; i++) {
    sum[i + 1] = sum[i] + dp[2][i + 1];
  }
  int x;
  for (int i = 3; i <= 3 * n; i++) {
    if (sum[i] >= k) {
      x = i;
      break;
    }
  }
  k -= sum[x - 1];
  int y;
  for (int i = 1; i <= n; i++) {
    y = x - i;
    ll z = 0;
    if (y <= n + 1) {
      z = y - 1;
    } else if (y <= 2 * n) {
      z = 2 * n - y + 1;
    }
    if (k - z < 0) {
      cout << i << " ";
      y = i;
      break;
    }
    if (k - z == 0) {
      cout << i << " " << min((int)n, y - 1) << " " << max(1, y - (int)n)
           << endl;
      return 0;
    }
    k -= z;
  }
  for (int i = 1; i <= n; i++) {
    if (x - y <= i + n) {
      if (k == 0) {
        cout << i - 1 << " " << x - y - i + 1 << endl;
        return 0;
      } else {
        k--;
      }
    }
  }
}
