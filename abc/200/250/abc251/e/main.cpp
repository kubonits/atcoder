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
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<vector<ll> > dp(n + 1, vector<ll>(2));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i][0] = dp[i][1] = 1000000000000000000;
  }
  dp[0][0] = 0;
  dp[1][1] = a[n - 1];
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a[(i + n - 1) % n]);

    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a[(i + n - 1) % n]);
    if (i < n - 1) {
      dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + a[i]);
      dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + a[i]);
    }
  }
  cout << min(dp[n][0], dp[n - 1][1]) << endl;
}
