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
  int n, m, x, y, ans = -1000000000;
  cin >> n >> m;
  vector<int> a(n), mini(n);
  vector<vector<int> > g(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mini[i] = 2000000000;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] - mini[i]);
    for (int j = 0; j < g[i].size(); j++) {
      mini[g[i][j]] = min(mini[g[i][j]], min(mini[i], a[i]));
    }
  }
  cout << ans << endl;
}
