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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  double a, b, c, x;
  cin >> a >> b >> c >> x;
  if (x <= a) {
    cout << 1.0 << endl;
  } else if (x <= b) {
    cout << fixed << setprecision(10) << c / (b - a) << endl;
  } else {
    cout << 0.0 << endl;
  }
}
