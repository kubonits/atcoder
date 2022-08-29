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
#include <cstring>

int main() {
  int n, m, ans = 0, cnt1 = 0, cnt2 = 0, fs[2] = {}, ft[2] = {};
  cin >> n >> m;
  ans = m;
  vector<int> s(n), t(m);
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    fs[s[i]] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    ft[t[i]] = 1;
    if (i == 0 && s[0] != t[0]) {
      ans++;
    } else if (i != 0 && t[i] != t[i - 1]) {
      ans++;
    }
  }
  if (!fs[0] && ft[0] || !fs[1] && ft[1]) {
    cout << -1 << endl;
    return 0;
  }
  if (!fs[0] || !fs[1] || ans == m) {
    cout << m << endl;
    return 0;
  }

  int p = 0;
  while (s[0] == s[p]) {
    p++;
    cnt1++;
  }
  p = 0;
  while (s[0] == s[p]) {
    p += n - 1;
    p %= n;
    cnt2++;
  }
  cout << ans + min(cnt1, cnt2) - 1 << endl;
}
