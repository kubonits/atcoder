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
#define MOD 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<ll> > dp(n + 1, vector<ll>(10));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[1][a[0]] = 1LL;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i + 1][(j + a[i]) % 10] += dp[i][j];
      dp[i + 1][(j * a[i]) % 10] += dp[i][j];
      dp[i + 1][(j + a[i]) % 10] %= MOD;
      dp[i + 1][(j * a[i]) % 10] %= MOD;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << dp[n][i] << endl;
  }
}
