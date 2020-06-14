#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double a, b, h, m, x[2], y[2], d;
  cin >> a >> b >> h >> m;
  x[0] = a;
  y[0] = 0.0;
  d = m / 60.0 - (h + m / 60.0) / 12.0;
  d *= 2.0 * acos(-1);
  x[1] = b * cos(d);
  y[1] = b * sin(d);
  cout << fixed << setprecision(10)
       << sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]))
       << endl;
}