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
  ll t, a, b, c;
  cin >> t;
  while (t--) {
    ll ans = 0LL;
    cin >> a >> b >> c;
    ll x = min(b / 2LL, a / 2LL + c);
    ans += x;
    if (x <= c) {
      c -= x;
      x = min(c / 2LL, a);
      ans += x;
      a -= x;
      c -= x * 2LL;
      x = min(c, a / 3LL);
      ans += x;
      a -= 3LL * x;
    } else {
      a -= (x - c) * 2LL;
    }
    ans += (a * 2LL) / 10LL;
    cout << ans << endl;
  }
}
