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

ll bit[300001], n;

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

ll sum(int i) {
  ll s = 0;
  while (i > 0) {
    s += bit[i];
    s %= MOD;
    i -= (i & -i);
  }
  return s;
}

void add(int i, ll x) {
  while (i <= n) {
    bit[i] += x;
    bit[i] %= MOD;
    i += (i & -i);
  }
}

int main() {
  cin >> n;
  int cnt = 1;
  ll ans = 0LL;
  vector<int> a(n), dp(n + 1);
  set<int> s;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for (auto x : s) {
    m[x] = cnt++;
  }
  for (ll i = 0LL; i < n; i++) {
    ans += sum(m[a[i]]) * mod_pow(mod_pow(2, MOD - 2, MOD), n - i + 1LL, MOD);
    ans %= MOD;
    add(m[a[i]], mod_pow(2, n - i, MOD));
  }
  cout << ans << endl;
}
