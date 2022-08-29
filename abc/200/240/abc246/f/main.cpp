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
    kai[i] %= MOD2;
  }
  inv[200000] = mod_pow(kai[200000], MOD2 - 2LL, MOD2);
  for (ll i = 199999; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1);
    inv[i] %= MOD2;
  }
}

ll comb(ll r, ll c) {
  ll res;
  res = kai[r];
  res *= inv[c];
  res %= MOD2;
  res *= inv[r - c];
  res %= MOD2;
  return res;
}

ll sum[27];

void init2(ll l) {
  for (ll i = 1LL; i <= 26LL; i++) {
    sum[i] = mod_pow(i, l, MOD2) % MOD2;
    for (int j = 1; j < i; j++) {
      sum[i] += (MOD2 - comb(i, j) * sum[j] % MOD2);
      sum[i] %= MOD2;
    }
  }
}

ll calc(int x) {
  ll res = 0;
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (x & (1 << i)) {
      cnt++;
    }
  }
  return sum[cnt];
}

int main() {
  ll n, l, ans = 0LL;
  cin >> n >> l;
  vector<string> s(n);
  vector<int> f(1 << 26);
  init();
  init2(l);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int num = 0;
    for (int j = 0; j < s[i].length(); j++) {
      num += (1 << (s[i][j] - 'a'));
    }
    for (int j = 1; j <= num; j++) {
      if ((j & num) == j) {
        f[j] = 1;
      }
    }
  }
  for (int i = 0; i < (1 << 26); i++) {
    if (f[i] == 1) {
      ans += calc(i);
      ans %= MOD2;
    }
  }
  cout << ans << endl;
}
