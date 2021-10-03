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
  ll x, y, a, b, ans = 0LL, cnt = 0LL;
  cin >> x >> y >> a >> b;
  while (x < y) {
    ans = max(ans, cnt + (y - x - 1) / b);
    if (y / x < a) {
      break;
    }
    cnt++;
    x *= a;
  }
  cout << ans << endl;
}