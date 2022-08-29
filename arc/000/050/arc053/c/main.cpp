#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  int n;
  ll a, b, ans = 0LL, x = 0LL;
  vector<pair<ll, ll> > vm, vp, ve;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a == b) {
      ve.push_back({a, b});
    } else if (a - b > 0) {
      vp.push_back({b, a});
    } else {
      vm.push_back({a, b});
    }
  }
  sort(vm.begin(), vm.end());
  sort(vp.begin(), vp.end());
  for (int i = 0; i < vm.size(); i++) {
    x += vm[i].first;
    ans = max(ans, x);
    x -= vm[i].second;
    ans = max(ans, x);
  }
  for (int i = 0; i < ve.size(); i++) {
    x += ve[i].first;
    ans = max(ans, x);
    x -= ve[i].second;
    ans = max(ans, x);
  }
  for (int i = vp.size() - 1; i >= 0; i--) {
    x += vp[i].second;
    ans = max(ans, x);
    x -= vp[i].first;
    ans = max(ans, x);
  }
  cout << ans << endl;
}