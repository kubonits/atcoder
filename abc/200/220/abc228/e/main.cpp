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
  ll n, k, m;
  cin >> n >> k >> m;
  if (m % MOD == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll x = mod_pow(k % (MOD - 1LL), n, (MOD - 1LL));
  cout << mod_pow(m % MOD, x, MOD) << endl;
}
