#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll d, c[26], s[365][26], t[365], ans = 0, m, x, y;
  set<ll> se[26];
  cin >> d;
  for (int i = 0; i < 26; i++) {
    cin >> c[i];
    se[i].insert(0);
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < 26; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < d; i++) {
    cin >> t[i];
    t[i]--;
    se[t[i]].insert(i + 1);
    ans += s[i][t[i]];
    for (int j = 0; j < 26; j++) {
      ans -= (i + 1 - *se[j].rbegin()) * c[j];
    }
  }
  for (int i = 0; i < 26; i++) {
    se[i].insert(d + 1);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    y--;
    ans += s[x - 1][y] - s[x - 1][t[x - 1]];
    set<ll>::iterator it = se[t[x - 1]].find(x);
    it--;
    ll z = *se[t[x - 1]].upper_bound(x);
    ans -= c[t[x - 1]] * (z - x) * (x - *it);
    se[t[x - 1]].erase(x);
    t[x - 1] = y;
    it = se[y].lower_bound(x);
    it--;
    ans += c[y] * (*se[y].lower_bound(x) - x) * (x - *it);
    cout << ans << endl;
    se[y].insert(x);
  }
}