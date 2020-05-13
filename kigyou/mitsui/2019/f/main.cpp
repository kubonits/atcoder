#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll t[2], a[2], b[2];
  cin >> t[0] >> t[1] >> a[0] >> a[1] >> b[0] >> b[1];
  if ((a[0] - b[0]) * t[0] + (a[1] - b[1]) * t[1] == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  if ((a[0] - b[0]) * t[0] + (a[1] - b[1]) * t[1] < 0) {
    a[0] ^= b[0];
    b[0] ^= a[0];
    a[0] ^= b[0];
    a[1] ^= b[1];
    b[1] ^= a[1];
    a[1] ^= b[1];
  }
  b[0] -= a[0];
  a[0] = 0LL;
  b[1] -= a[1];
  a[1] = 0LL;
  ll x = b[0] * t[0] + b[1] * t[1];
  x *= -1LL;
  ll ans = 0LL;
  if (b[0] > 0) {
    ans += b[0] * t[0] / x;
    ans *= 2LL;
    if (b[0] * t[0] % x != 0LL) {
      ans++;
    }
  }
  cout << ans << endl;
}