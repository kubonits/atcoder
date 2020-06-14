#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll dp[520][100001];
ll n, q, v[300001], w[300001];

ll dfs(ll x, ll y, ll vv, ll ww) {
  if (ww > y) {
    return 0LL;
  }
  if (x < (1 << 8)) {
    return dp[x][y - ww] + vv;
  }
  return max(dfs(x / 2, y, vv + v[x], ww + w[x]), dfs(x / 2, y, vv, ww));
}

int main() {
  ll vv, l;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i + 1] >> w[i + 1];
  }
  for (ll i = 1LL; i <= min(n, (1LL << 8)); i++) {
    for (ll j = 100000LL; j >= 0; j--) {
      dp[i][j] = dp[i / 2LL][j];
      if (j - w[i] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i / 2][j - w[i]] + v[i]);
      }
    }
    for (ll j = 1; j <= 100000; j++) {
      dp[i][j] = max(dp[i][j], dp[i][j - 1]);
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> vv >> l;
    cout << dfs(vv, l, 0, 0) << endl;
  }
}