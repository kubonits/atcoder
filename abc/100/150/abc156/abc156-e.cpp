#include <algorithm>
#include <cstdio>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll kai[400001], inv[400001];
ll n, k;
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
  for (ll i = 1LL; i <= n; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD;
  }
  inv[n] = mod_pow(kai[n], MOD - 2LL, MOD);
  for (ll i = n - 1; i >= 0; i--) {
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
  scanf("%lld%lld", &n, &k);
  ll ans = 0;
  n *= 2;
  init();
  n /= 2LL;
  ans = comb(2LL * n - 1LL, n);
  ll x, y;
  for (ll i = k + 1LL; i < n; i++) {
    x = comb(i + n - i - 1, i);
    x *= comb(n, i);
    x %= MOD;
    ans -= x;
    if (ans < 0) {
      ans += 10LL * MOD;
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
}