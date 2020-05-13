#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k <= a) {
    cout << k << endl;
  } else if (k <= a + b) {
    cout << a << endl;
  } else {
    cout << a - (k - (a + b)) << endl;
  }
}