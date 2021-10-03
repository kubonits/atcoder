#include <algorithm>
#include <cmath>
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
ll kai[500001], inv[500001];
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
  for (ll i = 1LL; i <= 500000; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD;
  }
  inv[500000] = mod_pow(kai[500000], MOD - 2LL, MOD);
  for (ll i = 499999; i >= 0; i--) {
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
  ll m, ans, x;
  cin >> n >> m;
  init();
  ans = comb(m, n) * kai[n] % MOD;
  x = ans;
  for (ll i = 1; i <= n; i++) {
    if (i % 2LL == 1LL) {
      x += (MOD - comb(m - i, n - i) * comb(n, i) % MOD * kai[n - i] % MOD);
      x %= MOD;
    } else {
      x += comb(m - i, n - i) * comb(n, i) % MOD * kai[n - i] % MOD;
      x %= MOD;
    }
  }
  cout << ans * x % MOD << endl;
}