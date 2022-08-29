#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double xx, yy, x[10], y[10], ans = 1000.0, a[2], b[2], c[2];
  int n;
  cin >> xx >> yy >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    if (x[i] == x[(i + 1) % n]) {
      ans = min(ans, abs(xx - x[i]));
    } else if (y[i] == y[(i + 1) % n]) {
      ans = min(ans, abs(yy - y[i]));
    } else {
      a[0] = (y[i] - y[(i + 1) % n]) / ((x[i] - x[(i + 1) % n]));
      b[0] = y[i] - x[i] * a[0];
      a[1] = -1.0 / a[0];
      b[1] = yy - xx * a[1];
      c[0] = (b[1] - b[0]) / (a[0] - a[1]);
      c[1] = b[1] + a[1] * c[0];
      ans =
          min(ans, sqrt((xx - c[0]) * (xx - c[0]) + (yy - c[1]) * (yy - c[1])));
    }
  }
  cout << fixed << setprecision(7) << ans << endl;
}