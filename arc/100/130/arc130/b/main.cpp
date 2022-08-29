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
  ll h, w, q, x;
  cin >> h >> w >> x >> q;
  vector<ll> t(q), n(q), c(q), ans(x + 1);
  set<ll> sh, sw;
  for (int i = 0; i < q; i++) {
    cin >> t[i] >> n[i] >> c[i];
  }
  for (int i = q - 1; i >= 0; i--) {
    if (t[i] == 1 && sh.find(n[i]) == sh.end()) {
      ans[c[i]] += w;
      sh.insert(n[i]);
      h--;
    } else if (t[i] == 2 && sw.find(n[i]) == sw.end()) {
      ans[c[i]] += h;
      w--;
      sw.insert(n[i]);
    }
  }
  for (int i = 1; i <= x; i++) {
    cout << ans[i] << endl;
  }
}
