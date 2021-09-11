#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double a, b, c, pi = acos(-1), l, r, mid, e;
double calc(double t) { return a * t + b * sin(c * t * pi); }

int main() {
  cin >> a >> b >> c;
  l = 0.0;
  r = 1000.0;
  while (1) {
    mid = (l + r) / 2.0;
    e = calc(mid);
    if (abs(100.0 - e) <= 0.00000001) {
      cout << fixed << setprecision(10) << mid << endl;
      return 0;
    } else if (e < 100.0) {
      l = mid;
    } else {
      r = mid;
    }
  }
}