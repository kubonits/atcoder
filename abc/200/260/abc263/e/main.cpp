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
  int n;
  cin >> n;
  vector<ll> a(n + 1), sum(n + 2), b(n + 1), sum2(n + 2), p(n + 1), p2(n + 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  p[0] = 1LL;
  p2[0] = 1LL;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j <= i + a[i]; j++) {
      p2[j] += p2[i] * mod_pow(a[i], MOD2 - 2, MOD2) % MOD2;
    }
  }
  for (int i = 0; i <= n; i++) {
    cout << p2[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n - 1; i++) {
    if (i) {
      b[i] += b[i - 1];
      p[i] = p[i - 1] + b[i];
    }
    b[i + 1] += p[i] * mod_pow(a[i], MOD2 - 2, MOD2);
    b[i + 1 + a[i]] -= p[i] * mod_pow(a[i], MOD2 - 2, MOD2);
  }
  for (int i = 0; i <= n; i++) {
    cout << b[i] << " " << p[i] << endl;
  }
  for (int i = 0; i < n - 1; i++) {
    if (i) {
      sum[i] = sum[i - 1] + b[i];
      sum[i] %= MOD2;
      sum2[i] = sum2[i - 1] + sum[i];
      sum2[i] %= MOD2;
    }
    b[i + 1] += ((a[i] + 1LL) * mod_pow(a[i], MOD2 - 2LL, MOD2)) % MOD2;
    b[i + 1 + a[i]] -= ((a[i] + 1LL) * mod_pow(a[i], MOD2 - 2LL, MOD2)) % MOD2;
    // for (int j = 0; j <= n; j++) {
    //   cout << a[j] << " " << b[j] << " " << sum[j] << " " << sum2[j] << endl;
    // }
    // cout << endl;
  }
  sum[n - 1] = sum[n - 1 - 1] + b[n - 1];
  sum[n - 1] %= MOD2;
  sum2[n - 1] = sum2[n - 1 - 1] + sum[n - 1];
  sum2[n - 1] %= MOD2;
  cout << sum2[n - 1] % MOD2 << endl;
  sum[n] = sum[n - 1] + b[n];
  sum[n] %= MOD2;
  sum2[n] = sum2[n - 1] + sum[n];
  sum2[n] %= MOD2;
  cout << sum2[n] % MOD2 << endl;
  // for (int i = 0; i <= n; i++) {
  //   cout << a[i] << " " << b[i] << " " << sum[i] << " " << sum2[i] << endl;
  // }
}
