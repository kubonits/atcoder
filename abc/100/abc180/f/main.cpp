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

ll kai[200001], inv[200001], dp[610][610], dp2[610][610];
int n, k;
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n /= 2;
  }
  return res;
}
void init() {
  kai[0] = 1LL;
  for (ll i = 1LL; i <= 200000; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD;
  }
  inv[200000] = mod_pow(kai[200000], MOD - 2LL, MOD);
  for (ll i = 199999; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1);
    inv[i] %= MOD;
  }
}

ll comb(ll r, ll c) {
  ll res;
  res = kai[r];
  res *= inv[c];
  res %= MOD;
  res *= inv[r - c];
  res %= MOD;
  return res;
}

int main() {
  ll m, l;
  cin >> n >> m >> l;
  init();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= l; k++) {
        dp[i][j] = dp2[i][j] = 0;
      }
    }
  }
  dp[0][0] = dp2[0][0] = 1LL;
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= m; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      if (l >= 2) {
        dp[i + 2][j + 2] += dp[i][j] * (n - i - 1) % MOD;
        dp[i + 2][j + 1] += dp[i][j] * (n - i - 1) % MOD;
        dp[i + 2][j + 2] %= MOD;
        dp[i + 2][j + 1] %= MOD;
      }
      for (ll k = 3; k <= l; k++) {
        dp[i + k][j + k] += dp[i][j] * comb(n - i - 1, k - 1) % MOD *
                            kai[k - 1] % MOD * inv[2] % MOD;
        dp[i + k][j + k - 1] += dp[i][j] * comb(n - i - 1, k - 1) % MOD *
                                kai[k] % MOD * inv[2] % MOD;
        dp[i + k][j + k] %= MOD;
        dp[i + k][j + k - 1] %= MOD;
      }
    }
  }
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= m; j++) {
      if (l >= 2) {
        dp2[i + 1][j] += dp2[i][j];
        dp2[i + 1][j] %= MOD;
      }
      if (l >= 3) {
        dp2[i + 2][j + 2] += dp2[i][j] * (n - i - 1) % MOD;
        dp2[i + 2][j + 1] += dp2[i][j] * (n - i - 1) % MOD;
        dp2[i + 2][j + 2] %= MOD;
        dp2[i + 2][j + 1] %= MOD;
      }
      for (ll k = 3; k <= l - 1; k++) {
        dp2[i + k][j + k] += dp2[i][j] * comb(n - i - 1, k - 1) % MOD *
                             kai[k - 1] % MOD * inv[2] % MOD;
        dp2[i + k][j + k - 1] += dp2[i][j] * comb(n - i - 1, k - 1) % MOD *
                                 kai[k] % MOD * inv[2] % MOD;
        dp2[i + k][j + k] %= MOD;
        dp2[i + k][j + k - 1] %= MOD;
      }
    }
  }
  cout << (dp[n][m] + MOD - dp2[n][m]) % MOD << endl;
}