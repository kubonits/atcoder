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
  int n, m;
  cin >> n >> m;
  vector<ll> dp((1 << n)), a(m), b(m), ans(n);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  dp[1] = 1;
  for (int i = 1; i < (1 << n); i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if ((i & (1 << a[j])) == 0 && (i & (1 << b[j])) == 0) {
        cnt++;
      }
    }
    ll x = mod_pow(2, cnt, MOD) * dp[i] % MOD;
    cout << i << " " << x << endl;
    for (int j = 1; j < n; j++) {
      if (i & (1 << j)) {
        ans[j] += x;
        ans[j] %= MOD;
      }
    }
    for (int j = 0; j < m; j++) {
      if ((i & (1 << a[j])) && !(i & (1 << b[j]))) {
        dp[i | (1 << b[j])] += dp[i];
        dp[i | (1 << b[j])] %= MOD;
      } else if (!(i & (1 << a[j])) && (i & (1 << b[j]))) {
        dp[i | (1 << a[j])] += dp[i];
        dp[i | (1 << a[j])] %= MOD;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << endl;
  }
}