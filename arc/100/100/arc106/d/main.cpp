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

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n = n >> 1;
  }
  return res;
}

int main() {
  ll n, k;
  ll g[310][310];
  cin >> n >> k;
  vector<vector<ll> > x(n + 1);
  vector<ll> a(n + 1), sum(k + 1);
  for (int i = 0; i <= k; i++) {
    g[i][0] = g[i][i] = 1LL;
  }
  for (int i = 2; i <= k; i++) {
    for (int j = 1; j < k; j++) {
      g[i][j] = (g[i - 1][j - 1] + g[i - 1][j]) % MOD;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x[i].resize(k + 1);
    x[i][0] = 1LL;
    for (int j = 0; j < k; j++) {
      x[i][j + 1] = x[i][j] * a[i] % MOD;
    }
  }
  for (int i = 0; i <= k; i++) {
    sum[i] = 0;
    for (int j = 0; j < n; j++) {
      sum[i] += x[j][i];
      sum[i] %= MOD;
    }
  }
  cout << sum[1] * (n - 1LL) % MOD << endl;
  for (int i = 2; i <= k; i++) {
    ll ans = (n - 1LL) * sum[i] % MOD;
    for (ll j = 1; j < i; j++) {
      ll y = sum[j] * sum[i - j] % MOD;
      y += MOD - sum[i];
      y %= MOD;
      y *= mod_pow(2, MOD - 2, MOD);
      y %= MOD;
      y *= g[i][j];
      y %= MOD;
      ans += y;
      ans %= MOD;
    }
    cout << ans << endl;
  }
}