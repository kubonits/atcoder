#include <iostream>
#include <map>
#include <utility>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
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
  ll n, ans = 1LL, a, b, x = 0LL, y = 0LL, xy = 0LL, g;
  map<pair<ll, ll>, ll> m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (!a && !b) {
      xy++;
    } else if (!a) {
      x++;
    } else if (!b) {
      y++;
    } else if (a < 0 && b > 0) {
      g = gcd(-a, b);
      m[{a / g, b / g}]++;
    } else if (a > 0 && b < 0) {
      g = gcd(a, -b);
      m[{-a / g, -b / g}]++;
    } else if (a < 0 && b < 0) {
      a *= -1LL;
      b *= -1LL;
      g = gcd(a, b);
      m[{a / g, b / g}]++;
    } else {
      g = gcd(a, b);
      m[{a / g, b / g}]++;
    }
  }
  n -= xy;
  ans *= (mod_pow(2, x, MOD) + mod_pow(2, y, MOD) - 1LL) % MOD;
  n -= x + y;
  map<pair<ll, ll>, ll>::iterator it = m.begin();
  while (it != m.end() && it->first.first < 0) {
    ll a = mod_pow(2, it->second, MOD);
    n -= it->second;
    if (m.find({it->first.second, -it->first.first}) != m.end()) {
      a += mod_pow(2, m[{it->first.second, -it->first.first}], MOD) - 1LL;
      a %= MOD;
      n -= m[{it->first.second, -it->first.first}];
    }
    ans *= a;
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    it++;
  }
  ans *= mod_pow(2, n, MOD);
  cout << (ans + xy - 1LL + MOD) % MOD << endl;
}