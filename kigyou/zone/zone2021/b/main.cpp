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
  int n;
  double d, h, dd, hh, ans = 0.0;
  cin >> n >> d >> h;
  for (int i = 0; i < n; i++) {
    cin >> dd >> hh;
    if (dd == d) {
      ans = h;
    } else {
      ans = max(ans, h - (h - hh) / (d - dd) * d);
    }
  }
  cout << ans << endl;
}
