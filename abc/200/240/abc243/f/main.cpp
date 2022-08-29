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

ll kai[200001], inv[200001];
int n, m, k;
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
    kai[i] %= MOD2;
  }
  inv[200000] = mod_pow(kai[200000], MOD2 - 2LL, MOD2);
  for (ll i = 199999; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1);
    inv[i] %= MOD2;
  }
}

ll comb(ll r, ll c) {
  ll res;
  res = kai[r];
  res *= inv[c];
  res %= MOD2;
  res *= inv[r - c];
  res %= MOD2;
  return res;
}

ll calc(ll p, ll n, ll k) {
  ll res = comb(n, k);
  res *= mod_pow(p, k, MOD2);
  res %= MOD2;
  res *= mod_pow((1 - p + MOD2) % MOD2, n - k, MOD2);
  return res % MOD2;
}

int main() {
  cin >> n >> m >> k;
  ll sum = 0LL;
  vector<ll> w(n);
  vector<vector<ll> > p(n, vector<ll>(k + 1));
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    sum += w[i];
    sum %= MOD2;
  }
  init();
  vector<vector<vector<ll> > > dp(
      n + 1, vector<vector<ll> >(n + 1, vector<ll>(k + 1)));
  dp[0][0][0] = 1LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int l = 0; l <= k; l++) {
        if (i < n - 1) {
          dp[i + 1][j][l] +=
              dp[i][j][l] *
              calc(w[i] * mod_pow(sum, MOD2 - 2, MOD2) % MOD2, k - l, 0) % MOD2;
          dp[i + 1][j][l] %= MOD2;
          for (int o = 1; l + o <= k; o++) {
            dp[i + 1][j + 1][l + o] +=
                dp[i][j][l] *
                calc(w[i] * mod_pow(sum, MOD2 - 2, MOD2) % MOD2, k - l, o) %
                MOD2;
            dp[i + 1][j + 1][l + o] %= MOD2;
          }
        } else {
          if (l == k) {
            dp[i + 1][j][k] += dp[i][j][l];
            dp[i + 1][j][k] %= MOD2;
          } else {
            dp[i + 1][j + 1][k] += dp[i][j][l];
            dp[i + 1][j + 1][k] %= MOD2;
          }
        }
      }
    }
  }
  cout << dp[n][m][k] * kai[k] % MOD2 << endl;
}
