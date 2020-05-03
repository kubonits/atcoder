#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double a[3], ans, pi = acos(-1);
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  ans = (a[0] + a[1] + a[2]);
  ans = ans * ans;
  ans *= pi;
  if (a[2] > a[0] + a[1]) {
    ans -= (a[2] - a[0] - a[1]) * (a[2] - a[0] - a[1]) * pi;
  }
  cout << fixed << setprecision(7) << ans << endl;
}