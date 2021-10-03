#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll kai[2000001], inv[2000001], sum[2000001];
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

ll g(ll r, ll c) {
  ll res = 0LL;
  for (ll i = 0; i <= r; i++) {
    res += comb(i + c + 1, c);
    res %= MOD;
  }
  return res;
}
int main() {
  int r1, r2, c1, c2;
  ll ans = 0;
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
  n = 2LL * max(r2, c2) + 1LL;
  init();
  ans += g(r2, c2);
  ans -= g(r1 - 1, c2);
  if (ans < 0) {
    ans += MOD * (-ans / MOD + 1);
    ans %= MOD;
  }
  ans -= g(r2, c1 - 1);
  if (ans < 0) {
    ans += MOD * (-ans / MOD + 1);
    ans %= MOD;
  }
  ans += g(r1 - 1, c1 - 1);
  ans %= MOD;
  printf("%lld\n", ans);
}