//解説AC
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll n, m, v, p, x = 1LL, v2, cnt;
  ll l, r, mid;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  l = 0LL;
  r = 1000000000LL;
  while (l <= r) {
    mid = (l + r) / 2LL;
    cnt = 0LL;
    for (int i = 0; i < n; i++) {
      if (n - i < p) {
        cnt += m;
      } else {
        cnt += max(0LL, min(m, mid + m - a[i]));
      }
    }
    if (cnt >= m * v) {
      r = mid - 1LL;
    } else {
      l = mid + 1LL;
    }
  }
  cnt = 0LL;
  for (int i = 0; i < n; i++) {
    if (a[i] >= l && a[i] + m >= a[n - p]) {
      cnt++;
    }
  }
  cout << cnt << endl;
}