#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll a, n, m, l[100000], x, y;
  ll left, right, mid;
  vector<pair<ll, ll>> v;
  cin >> a >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  for (int i = 1; i < n; i++) {
    v.push_back({l[i] - l[i - 1] - 1LL, 0});
  }
  v.push_back({0, 0});
  v.push_back({2000000001, 0});
  sort(v.begin(), v.end());
  for (int i = 1; i < v.size(); i++) {
    v[i].second = v[i - 1].second + v[i].first;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    ll ans = min(l[0] - 1, x) + min(a - l[n - 1], y);
    ans += n;
    left = 0;
    right = n + 1;
    while (left <= right) {
      mid = (right + left) / 2LL;
      if (v[mid].first <= x + y) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    ans += v[right].second + (n - 1LL - right) * (x + y);
    cout << ans << endl;
  }
}