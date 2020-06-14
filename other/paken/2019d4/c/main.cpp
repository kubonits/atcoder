#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double l[3], r[3], ans = 0.0, left, right;
  for (int i = 0; i < 3; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = (int)l[0]; i < (int)min(r[1], r[2]) && i <= (int)r[0]; i++) {
    if (l[1] == r[1]) {
      left = 1.0;
    } else {
      left = (r[1] + 1.0 - max(l[1], (double)i + 1.0)) / (r[1] + 1.0 - l[1]);
    }
    if (l[2] == r[2]) {
      right = 1.0;
    } else {
      right = (r[2] + 1.0 - max(l[2], (double)i + 1.0)) / (r[2] + 1.0 - l[2]);
    }
    ans += left * right;
  }
  if (l[0] != r[0]) {
    ans /= (r[0] + 1.0 - l[0]);
  }
  cout << fixed << setprecision(8) << ans << endl;
}