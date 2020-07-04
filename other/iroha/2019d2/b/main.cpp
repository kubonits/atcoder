#include <iostream>
using namespace std;

int main() {
  double x, y, a, b, sx, sy, tx, ty, y1, y2;
  cin >> x >> y >> a >> b >> sx >> sy >> tx >> ty;
  if (sx > tx) {
    double temp = sx;
    sx = tx;
    tx = temp;
    temp = sy;
    sy = ty;
    ty = temp;
  }
  if (a != b) {
    y1 = (b - a) * sx / x + a;
    y2 = (b - a) * tx / x + a;
    if (sy >= y1 && ty <= y2 || sy <= y1 && ty >= y2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (sy >= a && ty <= a || sy <= a && ty >= a) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}