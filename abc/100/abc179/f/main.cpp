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
  ll n, ans, h, w, q, x, y;
  cin >> n >> q;
  vector<ll> a(n + 1), b(n + 1);
  ans = (n - 2) * (n - 2);
  for (int i = 0; i <= n; i++) {
    a[i] = b[i] = n;
  }
  h = w = n;
  while (q--) {
    cin >> x >> y;
    if (x == 1) {
      if (y < w) {
        ans -= h - 2;
        for (int j = y + 1; j < w; j++) {
          b[j] = h;
        }
        w = y;
      } else {
        ans -= b[y] - 2;
      }
    } else {
      if (y < h) {
        ans -= w - 2;
        for (int j = y + 1; j < h; j++) {
          a[j] = w;
        }
        h = y;
      } else {
        ans -= a[y] - 2;
      }
    }
  }
  cout << ans << endl;
}