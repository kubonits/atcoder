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

int dp[3001][3001];

int main() {
  int n;
  ll ans = 0LL;
  cin >> n;
  vector<ll> a(n), sum(n + 1), sum2(n + 1), v[3000], parent(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[1][i] = 1LL;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      v[j].clear();
    }
    v[0].push_back(0);
    for (int j = 0; j < n; j++) {
      sum[j + 1] = (sum[j] + a[j]) % i;
      ll x = sum[j + 1];
      if (!v[x].empty()) {
        parent[j] = v[x].back();
      } else {
        parent[j] = j + 1;
      }
      v[x].push_back(j + 1);
    }
    sum2[0] = dp[i - 1][0];
    for (int j = 0; j < n; j++) {
      if (parent[j] != j + 1) {
        dp[i][j + 1] += sum2[parent[j]];
        dp[i][j + 1] %= MOD;
        sum2[j + 1] = (sum2[parent[j]] + dp[i - 1][j + 1]) % MOD;
      } else {
        sum2[j + 1] = dp[i - 1][j + 1];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += dp[i][n];
    ans %= MOD;
  }
  cout << ans << endl;
}