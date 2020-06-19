#include <iostream>
using namespace std;

int main() {
  int a, b, t;
  cin >> a >> b >> t;
  for (int i = t; i < 10000; i++) {
    if (i % (b - a) == b % (b - a)) {
      cout << i << endl;
      return 0;
    }
  }
}