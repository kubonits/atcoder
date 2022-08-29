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
  ll n, ans = 0, x = 0LL, m = 0;
  cin >> n;
  for (int i = 0; i < 16; i++) {
    x *= 10LL;
    x++;
    ll y = 1LL;
    while (x * y <= n) {
      if ((x + 1LL) * y <= n) {
        ans += y;
      } else {
        ans += n - x * y + 1LL;
      }
      y *= 10LL;
    }
  }
  cout << ans << endl;
}
