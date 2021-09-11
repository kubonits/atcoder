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
  ll x, k, d;
  cin >> x >> k >> d;
  if (x > 0 && k > x / d) {
    k -= x / d;
    x -= x / d * d;
  } else if (x > 0) {
    cout << x - k * d << endl;
    return 0;
  } else if (k > abs(x / d)) {
    k -= abs(x / d) + 1;
    x += (abs(x / d) + 1) * d;
  } else {
    cout << abs(x + k * d) << endl;
    return 0;
  }
  if (k % 2 == 0) {
    cout << x << endl;
  } else {
    cout << abs(x - d) << endl;
  }
}