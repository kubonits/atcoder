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

int main() {
  int n, t;
  cin >> t;
  set<int> sp, sm;
  set<pair<pair<ll, ll>, ll> > p, m;
  while (t--) {
    cin >> n;
    ll ans = 0LL;
    sp.clear();
    sm.clear();
    p.clear();
    m.clear();
    vector<ll> k(n), l(n), r(n), a(n), f(n);
    for (int i = 0; i < n; i++) {
      a[i] = 0;
      f[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      cin >> k[i] >> l[i] >> r[i];
      ans += r[i];
      k[i]--;
      if (-(r[i] - l[i]) < 0LL) {
        m.insert({{-(r[i] - l[i]), k[i]}, i});
      } else {
        p.insert({{-(r[i] - l[i]), k[i]}, i});
      }
    }
    for (int i = 0; i < n; i++) {
      if (i < p.size()) {
        sp.insert(-i);
      } else {
        sm.insert(i);
      }
    }
    set<pair<pair<ll, ll>, ll> >::reverse_iterator it = p.rbegin();
    for (; it != p.rend(); it++) {
      if (sp.lower_bound(-it->first.second) != sp.end()) {
        ans += it->first.first;
        sp.erase(sp.lower_bound(-it->first.second));
      } else {
        sp.erase(sp.begin());
      }
    }
    set<pair<pair<ll, ll>, ll> >::iterator it2 = m.begin();
    for (; it2 != m.end(); it2++) {
      if (sm.upper_bound(it2->first.second) != sm.end()) {
        sm.erase(sm.upper_bound(it2->first.second));
      } else {
        sm.erase(sm.begin());
        ans += it2->first.first;
      }
    }
    cout << ans << endl;
  }
}