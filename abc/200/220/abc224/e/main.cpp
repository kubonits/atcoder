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
  int h, w, n;
  cin >> h >> w >> n;
  vector<deque<pair<int, int>>> dr(h + 1), dc(w + 1), xr(h + 1), xc(w + 1);
  vector<int> a(n), r(n), c(n), dp(n);
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i] >> a[i];
    dr[r[i]].push_back({a[i], i});
    dc[c[i]].push_back({a[i], i});
    q.push({a[i], i});
  }
  for (int i = 0; i <= h; i++) {
    sort(dr[i].begin(), dr[i].end());
  }
  for (int i = 0; i <= w; i++) {
    sort(dc[i].begin(), dc[i].end());
  }
  while (!q.empty()) {
    pair<int, int> p;
    p = q.top();
    int x = p.second, y = p.first;
    q.pop();
    if (!xc[c[x]].empty()) {
      for (int i = 0; i < xc[c[x]].size(); i++) {
        if (xc[c[x]][i].first > y) {
          dp[x] = max(dp[x], xc[c[x]][i].second + 1);
        }
      }
    }
    if (xc[c[x]].empty() || xc[c[x]].back().first != y) {
      xc[c[x]].push_back({y, dp[x]});
      if (xc[c[x]].size() == 3) {
        xc[c[x]].pop_front();
      }
    }

    if (!xr[r[x]].empty()) {
      for (int i = 0; i < xr[r[x]].size(); i++) {
        if (xr[r[x]][i].first > y) {
          dp[x] = max(dp[x], xr[r[x]][i].second + 1);
        }
      }
    }
    if (xr[r[x]].empty() || xr[r[x]].back().first != y) {
      xr[r[x]].push_back({y, dp[x]});
      if (xr[r[x]].size() == 3) {
        xr[r[x]].pop_front();
      }
    }
    xc[c[x]].back().second = max(xc[c[x]].back().second, dp[x]);
    xr[r[x]].back().second = max(xr[r[x]].back().second, dp[x]);
  }
  for (int i = 0; i < n; i++) {
    cout << dp[i] << endl;
  }
}
