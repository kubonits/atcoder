#include <algorithm>
#include <cstdio>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll kai[200001], inv[200001];
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
  ll N, a, b;
  scanf("%lld%lld%lld", &N, &a, &b);
  n = 200000;
  init();
  ll ans = mod_pow(2LL, N, MOD);
  ans--;
  ll x = 1LL, y = 1LL;
  for (ll i = 0LL; i < a; i++) {
    x *= (N - i);
    x %= MOD;
  }
  x *= inv[a];
  x %= MOD;
  for (ll i = 0; i < b; i++) {
    y *= (N - i);
    y %= MOD;
  }
  y *= inv[b];
  y %= MOD;
  ans -= x;
  if (ans < 0) {
    ans += 10LL * MOD;
  }
  ans -= y;
  if (ans < 0) {
    ans += 10LL * MOD;
  }
  ans %= MOD;
  printf("%lld\n", ans);
}