#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int flag;
  double a, b, x, pi = acos(-1), l, r, mid, th;
  cin >> a >> b >> x;
  if (a * a * b <= 2.0 * x) {
    flag = 0;
    l = 0.0;
    r = atan(b / a) * 360.0 / 2 / pi;
  } else {
    l = atan(b / a) * 360.0 / 2 / pi;
    r = 90.0;
    flag = 1;
  }
  for (int i = 0; i < 50; i++) {
    mid = (l + r) / 2.0;
    th = (90 - mid) / 180 * pi;
    if (flag == 0 && x + a * a * a / tan(th) / 2.0 >= a * a * b) {
      r = mid;
    } else if (flag == 0) {
      l = mid;
    } else if (flag == 1 && b * b * tan(th) * a / 2.0 >= x) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(7) << (l + r) / 2.0 << endl;
}