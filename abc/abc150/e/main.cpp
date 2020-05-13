#include <algorithm>
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n /= 2LL;
  }
  return res;
}

int main() {
  ll n, ans = 0LL;
  cin >> n;
  vector<ll> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());
  for (ll i = 0; i < n; i++) {
    ans += c[n - 1 - i] * (i + 2LL);
    ans %= MOD;
  }
  ans *= mod_pow(2LL, 2LL * n - 2LL, MOD);
  ans %= MOD;
  cout << ans << endl;
}