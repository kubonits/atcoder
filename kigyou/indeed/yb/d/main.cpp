#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll n, ans;
  ll c, a;
  vector<vector<ll> > v;
  cin >> n >> c;
  v.resize(c);
  for (ll i = 0LL; i < n; i++) {
    cin >> a;
    a--;
    v[a].push_back(i);
  }
  for (ll i = 0LL; i < c; i++) {
    ans = n * (n + 1LL) / 2LL;
    ans -= v[i][0] * (v[i][0] + 1LL) / 2LL;
    for (int j = 1; j < v[i].size(); j++) {
      ll x = v[i][j] - v[i][j - 1] - 1LL;
      ans -= x * (x + 1LL) / 2LL;
    }
    if (v[i].back() != n - 1LL) {
      ll x = n - 1LL - v[i].back();
      ans -= x * (x + 1LL) / 2LL;
    }
    cout << ans << endl;
  }
}