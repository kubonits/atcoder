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
  double n, ans = 0.0, x = 1.0;
  cin >> n;
  for (double i = 1.0; i <= n; i += 1.0) {
    ans += (n + 1) / 2.0 * i * x * i / n;
    x *= (n - i) / n;
  }
  cout << fixed << setprecision(10) << ans << endl;
}