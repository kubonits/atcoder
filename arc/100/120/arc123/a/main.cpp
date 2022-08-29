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
  ll a, b, c, ans = 1000000000000000000LL;
  cin >> a >> b >> c;
  if (b - a == c - b) {
    ans = 0LL;
  }
  if (b - a > c - b) {
    ans = min(ans, b - a - (c - b));
  }
  if (b - a < c - b) {
    ans = min(ans, (c - b - (b - a)) / 2LL + (c - b - (b - a)) % 2LL * 2LL);
  }
  cout << ans << endl;
}
