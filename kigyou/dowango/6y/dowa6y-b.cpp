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
  int x[100000];
  ll y[100010], sum[100001] = {};
  ll ans = 0;
  scanf("%d", &n);
  init();
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (ll i = 1; i < n; i++) {
    y[i] = mod_pow(i, MOD - 2LL, MOD);
    sum[i] = sum[i - 1] + y[i];
    sum[i] %= MOD;
  }
  for (int i = 1; i <= n; i++) {
    ll a = (x[i] - x[i - 1]);
    a %= MOD;
    a *= sum[i];
    a %= MOD;
    ans += a;
    ans %= MOD;
  }
  ans *= kai[n - 1];
  ans %= MOD;
  printf("%lld\n", ans);
}