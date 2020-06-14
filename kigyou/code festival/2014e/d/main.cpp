#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
int main() {
  int n, m, x, y, p = 0, ans = 0;
  vector<vector<pii> > v(100001);
  vector<int> a;
  priority_queue<pii, vector<pii>, greater<pii> > q;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v[x].push_back({y, i});
  }
  a.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 1; i <= 100000; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      q.push(v[i][j]);
    }
    for (; p < m && a[p] == i; p++) {
      while (!q.empty() && q.top().first < a[p]) {
        q.pop();
      }
      if (!q.empty()) {
        ans++;
        q.pop();
      }
    }
  }
  cout << ans << endl;
}