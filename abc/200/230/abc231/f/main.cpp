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

ll bit[200002], n;

ll sum(ll i) {
  ll s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}

void add(ll i, ll x) {
  while (i <= n) {
    bit[i] += x;
    i += (i & -i);
  }
}

int main() {
  cin >> n;
  ll ans = 0LL;
  ll cnt = 0;
  vector<ll> a(n), b(n);
  vector<pair<ll, ll> > p(n);
  map<ll, ll> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    p[i] = {a[i], -b[i]};
  }
  sort(b.begin(), b.end());
  sort(p.begin(), p.end());
  m[b[0]] = 1;
  cnt = 2;
  for (int i = 1; i < n; i++) {
    if (b[i] != b[i - 1]) {
      m[b[i]] = cnt;
      cnt++;
    }
  }
  cnt = 0;
  for (ll i = 0LL; i < n; i++) {
    add(m[-p[i].second], 1LL);
    ans += i + 1LL - sum(m[-p[i].second] - 1);
    if (i != 0 && p[i] == p[i - 1]) {
      cnt++;
    } else {
      ans += cnt * (cnt + 1LL) / 2LL;
      cnt = 0;
    }
  }
  ans += cnt * (cnt + 1LL) / 2LL;
  cout << ans << endl;
}
