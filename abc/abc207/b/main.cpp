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
  ll a, b, c, d, e = 0, ans = 0;
  cin >> a >> b >> c >> d;
  if (b >= c * d) {
    cout << -1 << endl;
    return 0;
  }
  while (a > d * e) {
    a += b;
    e += c;
    ans++;
  }
  cout << ans << endl;
}