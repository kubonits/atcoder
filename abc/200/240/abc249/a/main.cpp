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
  int a, b, c, d, e, f, x, y = 0, z = 0;
  cin >> a >> b >> c >> d >> e >> f >> x;
  int xx = x;
  while (xx > 0) {
    if (xx >= a) {
      xx -= a + c;
      y += a * b;
    } else {
      y += xx * b;
      xx = 0;
    }
  }
  xx = x;
  while (xx > 0) {
    if (xx >= d) {
      xx -= d + f;
      z += d * e;
    } else {
      z += xx * e;
      xx = 0;
    }
  }
  if (y == z) {
    cout << "Draw" << endl;
    return 0;
  }
  cout << (y > z ? "Takahashi" : "Aoki") << endl;
}
