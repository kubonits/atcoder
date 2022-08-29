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
  ll res = 1LL;
  // cout << r << " " << c << endl;
  for (ll i = r - c + 1LL; i <= r; i++) {
    res *= i;
    res %= MOD;
  }
  res *= inv[c];
  res %= MOD;
  return res;
}

int main() {
  int n;
  ll a[2000], ans = 1LL, l, r;
  cin >> n;
  init();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  l = 0LL;
  while (l < n) {
    // cout << l << endl;
    while (l < n && a[l] != -1) {
      l++;
    }
    if (l == n) {
      break;
    }
    r = l;
    l--;
    while (r < n && a[r] == -1) {
      r++;
    }
    ans *= comb(a[r] - a[l] + r - l - 1LL, r - l - 1LL);
    ans %= MOD;
    l = r;
  }
  cout << ans << endl;
}