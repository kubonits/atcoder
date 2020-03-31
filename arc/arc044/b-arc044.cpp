#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
typedef long long ll;

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

ll mod_pow2(ll x, ll n, ll mod) {
  if (n == 0) {
    return 1;
  }
  ll res = mod_pow2(x * x % mod, n / 2, mod);
  if (n & 1) {
    res = res * x % mod;
  }
  return res;
}

int main() {
  int n, a[100000], md = 0;
  ll ans = 0, d[100000] = {};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    d[a[i]]++;
    if (i == 0 && a[i] == 0) {
      ans = 1;
    }
    if (i != 0 && a[i] == 0) {
      ans = 0;
    }
    md = max(md, a[i]);
  }

  for (int i = 1; i < n; i++) {
    ans *= (mod_pow(2LL, d[a[i] - 1], MOD) - 1LL);
    ans %= MOD;
  }
  for (int i = 1; i <= md; i++) {
    ll x = d[i] * (d[i] - 1) / 2;
    ans *= mod_pow(2, x, MOD);
    ans %= MOD;
  }
  printf("%lld\n", ans);
}