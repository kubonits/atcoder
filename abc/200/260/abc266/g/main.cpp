#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

ll kai[3000001], inv[3000001];
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
  for (ll i = 1LL; i <= 3000000; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD2;
  }
  inv[3000000] = mod_pow(kai[3000000], MOD2 - 2LL, MOD2);
  for (ll i = 2999999; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1);
    inv[i] %= MOD2;
  }
}

ll comb(ll r, ll c) {
  ll res;
  res = kai[r];
  res *= inv[c];
  res %= MOD2;
  res *= inv[r - c];
  res %= MOD2;
  return res;
}

int main() {
  ll r, g, b, k, ans = 1LL;
  cin >> r >> g >> b >> k;
  r -= k;
  g -= k;
  init();
  ans = comb(k + b, b);
  if (r) {
    ans *= comb(k + b + r, r);
    ans %= MOD2;
  }
  if (g) {
    ans *= comb(k + b + g, g);
    ans %= MOD2;
  }
  cout << ans << endl;
}
