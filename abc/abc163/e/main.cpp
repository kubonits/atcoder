#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
ll n, a[2000], f1[2000], f2[2000], ans;
vector<ll> v;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int k = 0; k < (n) / 2; k++) {
    ll x = -1LL, y = -1LL, p = -1LL, q = -1LL;
    for (int i = 0; i < n; i++) {
      if (f1[i] == 0 && x < a[i]) {
        q = p;
        y = x;
        x = a[i];
        p = i;
      } else if (f1[i] == 0 && y < a[i]) {
        y = a[i];
        q = i;
      }
    }

    ll l = min(p, q), r = max(p, q);
    f1[r] = 1;
    f1[l] = 1;
    ans += a[r] * labs(r - k) + a[l] * labs(n - 1 - k - l);
  }
  ll xx;
  if (n % 2) {
    for (int i = 0; i < n; i++) {
      if (f1[i] == 0) {
        xx = i;
        break;
      }
    }
    ans += a[xx] * labs(xx - n / 2);
  }

  cout << ans << endl;
}