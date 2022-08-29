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

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  ll l, r, ans = 0LL;
  cin >> l >> r;
  for (ll i = l; i <= min(l + 100LL, r); i++) {
    for (ll j = r; j >= 0; j--) {
      if (gcd(i, j) == 1) {
        ans = max(ans, j - i);
        break;
      }
    }
  }
  cout << ans << endl;
}
