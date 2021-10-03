#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

#define MOD 1000000007
using namespace std;
typedef long long ll;
ll kai[200001], inv[200001];
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
  ll a[100001];
  ll ans = 0;
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  if (k == 1) {
    printf("0\n");
    return 0;
  }
  sort(a, a + n);
  a[n] = a[n - 1] + 1;
  init();
  for (ll i = 0; i < n; i++) {
    if (i >= k - 1) {
      ll y = a[i];
      if (a[i] < 0) {
        y = MOD + a[i];
        y %= MOD;
      }
      y *= comb(i, k - 1);
      y %= MOD;
      ans += y;

      ans %= MOD;
    }
    if (n - i >= k) {
      ll y = a[i];
      if (a[i] < 0) {
        y = MOD + a[i];
        y %= MOD;
      }
      y *= comb(n - i - 1, k - 1);
      y %= MOD;

      y = MOD - y;
      y %= MOD;
      ans += y;
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
}