#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define MOD 1777777777
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
  ll n, k, ans = 1LL, x = 1LL, y;
  cin >> n >> k;
  for (ll i = 1; i <= k; i++) {
    x *= i % MOD;
    x %= MOD;
    ans *= (n + 1LL - i) % MOD;
    ans %= MOD;
  }
  ans *= mod_pow(x, MOD - 2LL, MOD);
  ans %= MOD;
  x = 0LL;
  y = 1LL;
  for (ll i = 2; i <= k; i++) {
    x *= i;
    x += (MOD + y);
    x %= MOD;
    y *= -1LL;
  }
  ans *= x;
  ans %= MOD;
  cout << ans << endl;
}