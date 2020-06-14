#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int h, w;
  ll k, v, ans = 0;
  cin >> h >> w >> k >> v;
  vector<vector<ll> > a(h + 1), sum(h + 1);
  for (int i = 0; i <= h; i++) {
    a[i].resize(w + 1);
    sum[i].resize(w + 1);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      sum[i + 1][j + 1] = sum[i + 1][j] + a[i][j];
    }
    if (i) {
      for (int j = 0; j <= w; j++) {
        sum[i + 1][j] += sum[i][j];
      }
    }
  }
  for (ll i = 0; i < h; i++) {
    for (ll j = i + 1; j <= h; j++) {
      for (ll x = 0; x < w; x++) {
        for (ll y = x + 1; y <= w; y++) {
          if (v >= sum[j][y] - sum[i][y] - sum[j][x] + sum[i][x] +
                       (j - i) * (y - x) * k) {
            ans = max(ans, (j - i) * (y - x));
          }
        }
      }
    }
  }
  cout << ans << endl;
}