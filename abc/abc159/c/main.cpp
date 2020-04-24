#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double l;
  cin >> l;
  cout << fixed << setprecision(7) << l * l * l / 27.0 << endl;
}