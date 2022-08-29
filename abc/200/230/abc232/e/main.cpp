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
  ll h, w, k, x1, x2, y1, y2;
  cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
  if (k == 1 && (x1 == x2 && y1 != y1 || x1 != x2 && y1 == y2)) {
    cout << 1 << endl;
    return 0;
  }
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (k == 2) {
    if (x1 != x2 && y1 != y2) {
      cout << 2 << endl;
      return 0;
    }
    if (x1 == x2 && y1 == y2) {
      cout << h + w - 2LL << endl;
      return 0;
    }
    if (x1 != x2) {
      cout << h - 2 << endl;
      return 0;
    } else {
      cout << w - 2 << endl;
    }
  }
}
