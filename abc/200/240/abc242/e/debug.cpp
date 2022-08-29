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

ll calc(int n, string s, string t) {
  if (t.length() == (n + 1) / 2) {
    string u = s.substr(0, n / 2);
    reverse(u.begin(), u.end());
    if (s < t + u) {
      return 0;
    }
    return 1;
  }
  ll res = 0;
  string u = "A";
  for (int i = 0; i < 26; i++) {
    res += calc(n, s, t + u);
    res %= MOD2;
    u[0]++;
  }
  return res;
}

int main() {
  int n, t;
  string s;
  t = 10000;
  while (t--) {
    if (t % 100 == 0) {
      cout << t << endl;
    }
    // cin >> n >> s;
    n = 6;
    s = "AAAAAA";
    for (int i = 0; i < 6; i++) {
      s[i] += rand() % 26;
    }
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
    // cout << endl;
    // cout << ans << endl;
    if (ans != calc(n, s, "")) {
      cout << n << " " << s << endl;
      cout << ans << " " << calc(n, s, "") << endl;
      return 0;
    }
  }
}
