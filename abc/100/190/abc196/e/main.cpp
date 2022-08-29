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
  ll n, q, mini, maxi;
  ll x, l, r, m, minix, maxx, dx;
  cin >> n;
  vector<ll> a(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> t[i];
  }
  mini = 0;
  l = -1000000000LL;
  r = 1000000000LL;
  minix = -1000000000LL;
  maxx = 1000000000;
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) {
      minix += a[i];
      maxx += a[i];
    } else if (t[i] == 2) {
      minix = max(minix, a[i]);
      maxx = max(maxx, a[i]);
    } else {
      minix = min(minix, a[i]);
      maxx = min(maxx, a[i]);
    }
  }
  while (l <= r) {
    m = (l + r) / 2;
    x = m;
    for (int i = 0; i < n; i++) {
      if (t[i] == 1) {
        x += a[i];
      } else if (t[i] == 2) {
        x = max(x, a[i]);
      } else {
        x = min(x, a[i]);
      }
    }
    if (x == minix) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  mini = r;
  l = -1000000000;
  r = 1000000000;
  while (l <= r) {
    m = (l + r) / 2;
    x = m;
    for (int i = 0; i < n; i++) {
      if (t[i] == 1) {
        x += a[i];
      } else if (t[i] == 2) {
        x = max(x, a[i]);
      } else {
        x = min(x, a[i]);
      }
    }
    if (x == maxx) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  maxi = l;
  l = -1000000000;
  r = 1000000000;
  while (l <= r) {
    m = (l + r) / 2;
    x = m;
    for (int i = 0; i < n; i++) {
      if (t[i] == 1) {
        x += a[i];
      } else if (t[i] == 2) {
        x = max(x, a[i]);
      } else {
        x = min(x, a[i]);
      }
    }
    if (x == maxx) {
      r = m - 1;
    } else if (x == minix) {
      l = m + 1;
    } else {
      dx = x - m;
      break;
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x;
    if (x <= mini) {
      cout << minix << endl;
    } else if (x >= maxi) {
      cout << maxx << endl;
    } else {
      cout << x + dx << endl;
    }
  }
}
