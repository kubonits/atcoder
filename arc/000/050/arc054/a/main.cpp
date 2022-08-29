#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int l, x, y, s, d, z;
  double ans = 1000000000.0;
  cin >> l >> x >> y >> s >> d;
  z = (l + d - s) % l;
  ans = min(ans, (double)z / (double)(x + y));
  if (x < y) {
    z = (l + s - d) % l;
    ans = min(ans, (double)z / (double)(y - x));
  }
  cout << fixed << setprecision(15) << ans << endl;
}