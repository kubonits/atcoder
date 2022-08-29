#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int n;
  double c[1000], x[1000], y[1000], l, r, mid, xmin, xmax, ymin, ymax;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> c[i];
  }
  l = 0.0;
  r = 1000000000.0;
  for (int k = 0; k < 100; k++) {
    mid = (l + r) / 2.0;
    xmin = ymin = -100000.0;
    xmax = ymax = 100000.0;
    for (int i = 0; i < n; i++) {
      xmax = min(xmax, x[i] + mid / c[i]);
      ymax = min(ymax, y[i] + mid / c[i]);
      xmin = max(xmin, x[i] - mid / c[i]);
      ymin = max(ymin, y[i] - mid / c[i]);
    }
    if (xmin <= xmax && ymin <= ymax) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(6) << (l + r) / 2.0 << endl;
}