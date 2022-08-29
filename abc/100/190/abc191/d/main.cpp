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
  double xx, yy, rr;
  ll x, y, r;
  ll ans = 0LL;
  cin >> xx >> yy >> rr;
  x = xx * 10000.0;
  y = yy * 10000.0;
  r = rr * 10000.0;
  for (ll i = (x - r + 9999) / 10000 * 10000; i <= x + r; i += 10000) {
    cout << i << endl;
    cout << (y + (ll)sqrt(r * r - (x - i) * (x - i))) / 10000 << " "
         << (y - (ll)sqrt(r * r - (x - i) * (x - i))) / 10000 << endl;
    ans += (y + sqrt(r * r - (x - i) * (x - i))) / 10000 -
           (y - sqrt(r * r - (x - i) * (x - i))) / 10000 + 1LL;
  }
  cout << ans << endl;
}
