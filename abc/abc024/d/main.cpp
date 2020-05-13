#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
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
  ll a, b, c, d, ab, ac, bd, cd;
  cin >> a >> b >> c;
  d = b + c;
  d %= MOD;
  ab = b * mod_pow(a, MOD - 2, MOD) % MOD;
  ac = c * mod_pow(a, MOD - 2, MOD) % MOD;
  bd = d * mod_pow(b, MOD - 2, MOD) % MOD;
  cd = d * mod_pow(c, MOD - 2, MOD) % MOD;
  cout << mod_pow((bd - ac + MOD) % MOD, MOD - 2, MOD) - 1 << " "
       << mod_pow((cd - ab + MOD) % MOD, MOD - 2, MOD) - 1 << endl;
}