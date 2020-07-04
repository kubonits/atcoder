#include <iostream>
#include <map>
using namespace std;
int main() {
  int n, q, a, l, r, x, ans, y, z;
  map<int, int> m;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (m.find(a) == m.end()) {
      m.insert({a, 1});
    } else {
      m[a]++;
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> l >> r >> x;
    ans = y = 0;
    while (m.lower_bound(l) != m.end() && m.lower_bound(l)->first <= r) {
      z = m.lower_bound(l)->first;
      y += m[z];
      if (m[z] % 2 == 1) {
        ans ^= z;
      }
      m.erase(z);
    }
    cout << ans << endl;
    if (y) {
      if (m.find(x) == m.end()) {
        m.insert({x, y});
      } else {
        m[x] += y;
      }
    }
  }
}