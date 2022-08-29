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
  ll n, ans = 2000000000000000000;
  cin >> n;
  for (ll i = 0; i * i * i <= n; i++) {
    ll left = 0LL, right = 1000000, mid;
    while (left <= right) {
      mid = (left + right) / 2LL;
      if (i * i * i + i * i * mid + i * mid * mid + mid * mid * mid >= n) {
        right = mid - 1LL;
      } else {
        left = mid + 1LL;
      }
    }
    ans = min(ans,
              i * i * i + i * i * left + i * left * left + left * left * left);
  }
  cout << ans << endl;
}
