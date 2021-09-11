#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
ll n, p[100000], a[100001], ans;
set<ll> l, r;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    a[p[i]] = i + 1LL;
  }
  l.insert(-a[n]);
  r.insert(a[n]);
  for (ll i = n - 1LL; i >= 1LL; i--) {
    set<ll>::iterator left = l.upper_bound(-a[i]);
    set<ll>::iterator right = r.lower_bound(a[i]);
    if (left == l.end()) {
      set<ll>::iterator it = r.upper_bound(*right);
      if (it != r.end()) {
        ans += i * a[i] * (*it - *right);
      } else {
        ans += i * a[i] * (n + 1LL - *right);
      }
    } else if (right == r.end()) {
      set<ll>::iterator it = l.upper_bound(*left);
      if (it != l.end()) {
        ans += i * (n + 1LL - a[i]) * (*it - *left);
      } else {
        ans += i * (n + 1LL - a[i]) * (-*left);
      }
    } else {
      set<ll>::iterator it = r.upper_bound(*right);
      if (it != r.end()) {
        ans += i * (a[i] + *left) * (*it - *right);
      } else {
        ans += i * (a[i] + *left) * (n + 1LL - *right);
      }
      it = l.upper_bound(*left);
      if (it != l.end()) {
        ans += i * (*right - a[i]) * (*it - *left);
      } else {
        ans += i * (*right - a[i]) * (-*left);
      }
    }
    l.insert(-a[i]);
    r.insert(a[i]);
  }
  cout << ans << endl;
}