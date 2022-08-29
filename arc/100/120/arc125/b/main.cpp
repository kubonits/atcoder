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
#define MOD 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  ll n, left, right, mid, ans = 0LL, p;
  cin >> n;
  ll x = sqrt(n);
  ans += x * (x + 1LL) / 2LL;
  ans %= MOD;
  p = x + 1LL;
  while (x) {
    left = p;
    right = n;
    while (left <= right) {
      mid = (left + right) / 2LL;
      if (n + x * x >= 2 * mid * x) {
        left = mid + 1LL;
      } else {
        right = mid - 1LL;
      }
    }
    ans += (left - p) * x % MOD;
    ans %= MOD;
    p = left;
    x--;
  }
  cout << ans << endl;
}