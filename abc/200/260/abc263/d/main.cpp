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
  ll n, l, r, ans;
  cin >> n >> l >> r;
  vector<ll> a(n), sum(n + 1), minil(n + 1), minir(n + 1), sum2(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    sum2[i] = sum2[i + 1] + a[i];
  }
  ans = sum[n];
  for (ll i = 1LL; i < n + 1LL; i++) {
    minil[i] = min(minil[i - 1] + a[i - 1], l * i);
  }
  for (ll i = n - 1; i >= 0; i--) {
    minir[i] = min(minir[i + 1] + a[i], r * (n - i));
  }
  for (int i = 0; i <= n; i++) {
    ans = min(ans, minil[i] + minir[i]);
  }
  cout << ans << endl;
}
