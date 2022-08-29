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

int calc(ll x, ll y, ll a, ll b, ll c) {
  y -= (a + x - 1) / x;
  if (y <= 0) {
    return 0;
  }
  if ((b + y - 1LL) / y + (c + y - 1LL) / y <= x) {
    return 1;
  }
  return 0;
}

int main() {
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  if ((a + x - 1LL) / x + (b + x - 1LL) / x + (c + x - 1LL) / x <= y) {
    cout << "Yes" << endl;
    return 0;
  }
  if ((a + y - 1LL) / y + (b + y - 1LL) / y + (c + y - 1LL) / y <= x) {
    cout << "Yes" << endl;
    return 0;
  }
  if (calc(x, y, a, b, c) || calc(x, y, b, a, c) || calc(x, y, c, a, b) ||
      calc(y, x, a, b, c) || calc(y, x, b, a, c) || calc(y, x, c, a, b)) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
