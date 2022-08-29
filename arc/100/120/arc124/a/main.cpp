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

int main() {
  int n, k, x;
  char c;
  cin >> n >> k;
  vector<ll> l(k + 1), r(k + 1), f(n + 1), sum(n + 1);
  for (int i = 1; i <= k; i++) {
    l[i] = 1LL;
    r[i] = n;
  }
  for (int i = 1; i <= k; i++) {
    cin >> c >> x;
    if (c == 'R') {
      r[i] = x;
      f[x] = 1LL;
    } else {
      l[i] = x;
      f[x] = 1LL;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (ll j = l[i]; j <= r[i]; j++) {
      if (f[j] == 0) {
        sum[j]++;
      }
    }
  }
  ll ans = 1LL;
  for (int i = 1; i <= n; i++) {
    if (f[i] == 0) {
      ans *= sum[i];
      ans %= MOD2;
    }
  }
  cout << ans << endl;
}
