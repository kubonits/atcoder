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
  int n, m, q, w, v, l, r;
  cin >> n >> m >> q;
  vector<pair<int, int> > vp;
  vector<int> x(m);
  for (int i = 0; i < n; i++) {
    cin >> w >> v;
    vp.push_back({w, v});
  }
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  sort(vp.begin(), vp.end());
  while (q--) {
    cin >> l >> r;
    vector<int> a;
    priority_queue<int> pq;
    for (int i = 0; i < m; i++) {
      if (i < l - 1 || i >= r) {
        a.push_back(x[i]);
      }
    }
    sort(a.begin(), a.end());
    int p = 0, ans = 0;
    for (int i = 0; i < a.size(); i++) {
      while (p < n & vp[p].first <= a[i]) {
        pq.push(vp[p].second);
        p++;
      }
      if (!pq.empty()) {
        ans += pq.top();
        pq.pop();
      }
    }
    cout << ans << endl;
  }
}
