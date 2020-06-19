#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (y >= 0 && y % 2 == 0 && y >= abs(x * 2) &&
      (y % 4 == 0 && x % 2 == 0 || y % 4 && x % 2)) {
    cout << y / 2 << endl;
  } else {
    cout << -1 << endl;
  }
}