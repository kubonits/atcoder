#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double l, r, p, ml, mr, x, y;
  cin >> p;
  l = 0.0;
  r = p;
  for (int i = 0; i < 200; i++) {
    ml = (2.0 * l + r) / 3.0;
    mr = (l + 2.0 * r) / 3.0;
    x = ml + p * pow(2, -ml / 1.5);
    y = mr + p * pow(2, -mr / 1.5);
    if (x < y) {
      r = mr;
    } else {
      l = ml;
    }
  }
  cout << fixed << setprecision(10)
       << (l + r) / 2.0 + p * pow(2, -(l + r) / 3.0) << endl;
}