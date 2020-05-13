#include <iostream>
using namespace std;
int main() {
  int y, m, d;
  cin >> y >> m >> d;
  if (m == 1 || m == 2) {
    y--;
    m += 12;
  }
  cout << -(365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d -
            429) +
              (365 * 2014 + 2014 / 4 - 2014 / 100 + 2014 / 400 +
               306 * (5 + 1) / 10 + 17 - 429)
       << endl;
}