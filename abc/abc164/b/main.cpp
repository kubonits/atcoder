#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MOD 1000000007
using namespace std;

int main() {
  int a, b, c, d, flag = 0;
  cin >> a >> b >> c >> d;
  while (a > 0 && c > 0) {
    if (flag == 0) {
      c -= b;
      flag = 1;
    } else {
      a -= d;
      flag = 0;
    }
  }
  if (c <= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}