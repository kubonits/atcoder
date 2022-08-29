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
  int n, t;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    ll ans = 0LL;
    for (int i = 0; i < (n + 1) / 2; i++) {
      ans += (s[i] - 'A') * mod_pow(26LL, (n - 2 * (i + 1) + 1) / 2, MOD2);
      ans %= MOD2;
    }
    string t = s.substr(0, (n + 1) / 2);
    string u = s.substr(0, n / 2);
    reverse(u.begin(), u.end());
    if (s >= t + u) {
      ans++;
    }
    cout << ans % MOD2 << endl;
  }
}
