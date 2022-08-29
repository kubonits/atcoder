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
  double a, b, d;
  cin >> a >> b >> d;
  cout << fixed << setprecision(15)
       << a * cos(acos(-1) * d / 180.0) - b * sin(acos(-1) * d / 180.0) << " "
       << a * sin(acos(-1) * d / 180.0) + b * cos(acos(-1) * d / 180.0) << endl;
}
