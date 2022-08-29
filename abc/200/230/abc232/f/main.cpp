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

int n;
ll x, y, ans = 1000000000000000000;
vector<ll> a(18), b(18);
vector<ll> dp(1 << 18);

ll calc(int z) {
  ll res = 0;
  vector<ll> c, d, e;
  for (int i = 0; i < n; i++) {
    if (z & (1 << i)) {
      c.push_back(a[i]);
      d.push_back(b[i]);
      e.push_back(1 << i);
    }
  }
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  for (int i = 0; i < c.size(); i++) {
    res += llabs(c[i] - d[i]) * x;
  }
  res += (ll)(c.size() - 1) * y;
  dp[z] = res;
  int s = c.size();
  for (int i = 0; i < (1 << s - 1); i++) {
    int num = 0;
    for (int j = 0; j < s; j++) {
      if (i & (1 << j)) {
        num += e[j];
      }
    }
    res = min(res, dp[num] + dp[z ^ num]);
  }
  dp[z] = res;
  return res;
}

int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < (1 << n); i++) {
    calc(i);
  }
  cout << dp[(1 << n) - 1] << endl;
}
