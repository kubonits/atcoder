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

ll kai[2000001], inv[2000001];
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
  for (ll i = 1LL; i <= 2000000; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD;
  }
  inv[2000000] = mod_pow(kai[2000000], MOD - 2LL, MOD);
  for (ll i = 1999999; i >= 0; i--) {
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

ll calc(ll x, ll y) {
  if (y == 0LL) {
    return 1LL;
  }
  ll res = comb(x + y, x) * mod_pow(25, y, MOD);
  res %= MOD;
  res += calc(x + 1LL, y - 1LL);
  return res % MOD;
}

int main() {
  string s;
  cin >> k >> s;
  n = s.length();
  init();
  cout << calc(n, k) << endl;
}