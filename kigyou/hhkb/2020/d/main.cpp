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
  ll n, t, a, b, na, bb, nb;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    if (a < b) {
      a ^= b;
      b ^= a;
      a ^= b;
    }
    na = (n - a + 1LL);
    nb = (n - b + 1LL);
    bb = b * (b - 1) % MOD * mod_pow(2, MOD - 2, MOD) % MOD;
    ll ans = 1LL;
    ans = na * na % MOD * nb % MOD * nb % MOD;
    ll x = (a - b + 1LL) * (a - b + 1LL) % MOD;
    ans += MOD - x * na % MOD * na % MOD;
    ans %= MOD;
    ans += 4 * (MOD - na * na % MOD * (b - 1) % MOD * (b - 1)) % MOD;
    ans %= MOD;
    ans += 8 *
           (na * (b - 1) % MOD * b % MOD * (b - 1) % MOD *
            mod_pow(2, MOD - 2, MOD)) %
           MOD;
    ans %= MOD;
    ans += 4 * (MOD - bb * bb % MOD);
    ans %= MOD;
    cout << ans << endl;
    ans += 4 * (MOD - na * na % MOD) * (a - b + 1LL) % MOD * (b - 1LL) % MOD;
    ans %= MOD;
    cout << ans << endl;
    ans += 4 * (na * bb % MOD);
    ans %= MOD;
    cout << ans << endl;
  }
}