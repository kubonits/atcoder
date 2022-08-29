#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  double n, x[3], y[3], pi = acos(-1);
  cin >> n >> x[0] >> y[0] >> x[1] >> y[1];
  x[2] = (x[0] + x[1]) / 2.0;
  y[2] = (y[0] + y[1]) / 2.0;
  double r =
      sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]));
  cout << x[2] + (x[0] - x[2]) * cos(pi / n * 2.0) -
              (y[0] - y[2]) * sin(pi / n * 2.0)
       << " "
       << y[2] + (x[0] - x[2]) * sin(pi / n * 2.0) +
              (y[0] - y[2]) * cos(pi / n * 2.0)
       << endl;
}
