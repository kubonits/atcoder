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
#define MOD 998244353
using namespace std;
typedef long long ll;
#include <cstring>

ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n = n >> 1;
  }
  return res;
}

int main() {
  ll n, d, ans = 0LL;
  cin >> n >> d;
  vector<ll> v(d + 1), sum(d + 1);
  v[d] = mod_pow(2LL, d + 1LL, MOD);
  for (ll i = d - 1LL; i >= d - i; i--) {
    v[i] = mod_pow(2, i, MOD) * mod_pow(2, d - i - 1LL, MOD) % MOD;
    v[i] *= 2LL;
    v[i] %= MOD;
  }
  if (2 % 2LL == 0) {
    v[d / 2LL] *= mod_pow(2, MOD - 2LL, MOD);
    v[d / 2LL] %= MOD;
  }
  for (int i = 0; i < d; i++) {
    sum[i + 1] = sum[i] + v[i + 1];
    sum[i + 1] %= MOD;
  }
  for (ll i = 0LL; i < n; i++) {
    ll x = sum[min(d, n - i - 1LL)] - sum[min(d - d / 2LL - 1LL, n - i - 1LL)] +
           MOD;
    x %= MOD;
    x *= mod_pow(2, i, MOD);
    x %= MOD;
    ans += x;
    ans %= MOD;
  }
  cout << ans << endl;
}
