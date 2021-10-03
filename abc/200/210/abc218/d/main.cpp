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
  ll n, x, y, cnt = 0, ans = 0LL;
  cin >> n;
  vector<vector<int> > v(n);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (m.find(x) == m.end()) {
      m.insert({x, cnt++});
    }
    v[m[x]].push_back(y);
  }
  for (int i = 0; i < cnt; i++) {
    sort(v[i].begin(), v[i].end());
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cnt = 0LL;
      x = 0;
      y = 0;
      while (x < v[i].size() && y < v[j].size()) {
        if (v[i][x] < v[j][y]) {
          x++;
        } else if (v[i][x] > v[j][y]) {
          y++;
        } else {
          x++;
          y++;
          cnt++;
        }
      }
      ans += cnt * (cnt - 1LL) / 2LL;
    }
  }
  cout << ans << endl;
}
