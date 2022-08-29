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
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int> > g(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int q, x, k;
  cin >> q;
  for (int i = 0; i < q; i++) {
    set<int> s;
    cin >> x >> k;
    s.clear();
    s.insert(x);
    for (int j = 0; j < k; j++) {
      set<int> ss;
      for (auto&& y : s) {
        ss.insert(y);
      }
      for (auto&& y : ss) {
        for (int l = 0; l < g[y].size(); l++) {
          s.insert(g[y][l]);
        }
      }
    }
    int ans = 0;
    for (auto&& x : s) {
      ans += x;
    }
    cout << ans << endl;
  }
}
