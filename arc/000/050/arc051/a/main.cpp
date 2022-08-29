#include <iostream>
using namespace std;
int main() {
  int x[3], y[3], r;
  cin >> x[0] >> y[0] >> r;
  cin >> x[1] >> y[1] >> x[2] >> y[2];
  if (x[0] - r >= x[1] && x[0] + r <= x[2] && y[0] - r >= y[1] &&
      y[0] + r <= y[2]) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  if ((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]) <= r * r &&
      (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[2]) * (y[0] - y[2]) <= r * r &&
      (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[1]) * (y[0] - y[1]) <= r * r &&
      (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]) <= r * r) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}