#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  int n, k, ans = 0, r, s, p;
  string t;
  map<char, int> m;
  cin >> n >> k >> r >> s >> p;
  m.insert({'r', p});
  m.insert({'s', r});
  m.insert({'p', s});
  cin >> t;
  for (int i = 0; i < n; i++) {
    if (i < k || t[i] != t[i - k]) {
      ans += m[t[i]];
    } else if (i + k < n && t[i] == t[i + k]) {
      t[i] = (113 ^ t[i - k] ^ t[i + k]);
    }
  }
  cout << ans << endl;
}