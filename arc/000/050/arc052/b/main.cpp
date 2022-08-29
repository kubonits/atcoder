#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int n, q;
  double x[100], r[100], h[100], v[100], a, b, sum = 0.0, pi = acos(-1), mi;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> r[i] >> h[i];
    v[i] = r[i] * r[i] * pi * h[i] / 3.0;
    sum += v[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    mi = 0.0;
    for (int i = 0; i < n; i++) {
      if (b <= x[i] || a >= x[i] + h[i]) {
        mi += v[i];
      } else {
        if (x[i] <= b && x[i] + h[i] >= b) {
          mi += v[i] * pow((x[i] + h[i] - b) / h[i], 3.0);
        }
        if (x[i] <= a && x[i] + h[i] >= a) {
          mi += v[i] - v[i] * pow((x[i] + h[i] - a) / h[i], 3.0);
        }
      }
    }
    cout << fixed << setprecision(4) << sum - mi << endl;
  }
}