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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  ll n, x, ans = 1000000000000000000, cnt = 0LL;
  cin >> n >> x;
  ans = x;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    ll xx = x % a[i];
    if (xx / a[i - 1] <= 1LL + (a[i] - xx) / a[i - 1]) {
      cnt += xx / a[i - 1];
    } else {
      cnt += (a[i] - xx) / a[i - 1];
      x += a[i];
    }
    x -= xx;
    ans = min(ans, cnt + x / a[i]);
  }
  cout << ans << endl;
}
