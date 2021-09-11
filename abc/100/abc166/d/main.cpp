#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  ll n, l, r, mid, x, y;
  cin >> n;
  for (ll i = 0LL; i <= 4000LL; i++) {
    x = i * i * i * i * i;
    l = -100;
    r = i;
    while (l <= r) {
      mid = (l + r) / 2LL;
      if (x - mid * mid * mid * mid * mid == n) {
        cout << i << " " << mid << endl;
        return 0;
      } else if (x - mid * mid * mid * mid * mid < n) {
        r = mid - 1LL;
      } else {
        l = mid + 1LL;
      }
    }
    if (x == l * l * l * l * l) {
      cout << i << " " << l << endl;
      return 0;
    }
    if (x == r * r * r * r * r) {
      cout << i << " " << r << endl;
      return 0;
    }
  }
}