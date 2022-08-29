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
  ll n, ans = 0, l, r, mid;
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    ll x = n / i;
    l = i;
    r = n;
    while (l <= r) {
      mid = (l + r) / 2LL;
      if (n / mid == x) {
        l = mid + 1LL;
      } else {
        r = mid - 1LL;
      }
    }
    ans += (l - i) * x;
    i = r;
  }
  cout << ans << endl;
}
