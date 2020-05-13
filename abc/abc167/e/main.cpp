#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll kai[200001], inv[200001];
ll dp[200001];

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
  ll n, m, k, ans = 0LL, cnt;
  cin >> n >> m >> k;
  init();
  for (int i = 0; i <= k; i++) {
    cnt = comb(n - 1LL, i);
    cnt *= m;
    cnt %= MOD;
    cnt *= mod_pow(m - 1LL, n - 1LL - i, MOD);
    cnt %= MOD;
    ans += cnt;
    ans %= MOD;
  }
  cout << ans << endl;
}