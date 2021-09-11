#include <iostream>
using namespace std;
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
ll kai[700001], inv[700001];
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
  for (ll i = 1LL; i <= 700000; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= MOD;
  }
  inv[700000] = mod_pow(kai[700000], MOD - 2LL, MOD);
  for (ll i = 699999; i >= 0; i--) {
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
  ll x, y, d;
  cin >> x >> y;
  d = x + y;
  d /= 3LL;
  if ((x + y) % 3 || x < d || y < d) {
    cout << 0 << endl;
    return 0;
  }
  init();
  if (x < y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  cout << comb(d, (d - (x - y)) / 2LL) << endl;
}