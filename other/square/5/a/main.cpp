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
  int n, t, ans = 0, a;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ans = max(ans, a);
    if (a % t >= ans % t) {
      ans += a % t - ans % t;
    } else {
      ans += a % t - ans % t + t;
    }
  }
  cout << ans << endl;
}