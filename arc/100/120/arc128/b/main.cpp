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

int calc(int x, int y, int z) {
  if (x < y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  int res = 0;
  if ((x - y) / 3 <= z) {
    return (x - y) / 3 + y + (x - y) / 3 * 2;
  }
}

int main() {
  int n, r, g, b;
  queue<pair<int, pair<int, int> > > q;
  set<pair<int, pair<int, int> > > s;
  cin >> n;
  while (n--) {
    cin >> r >> g >> b;
    int ans = 1000000000;
    if (r == g) {
      ans = min(ans, r);
    }
    if (r == b) {
      ans = min(ans, r);
    }
    if (g == b) {
      ans = min(ans, g);
    }
    if (abs(r - g) % 3 == 0) {
      ans = min(ans, calc(r, g, b));
    }
    if (abs(r - b) % 3 == 0) {
      ans = min(ans, calc(r, b, g));
    }
    if (abs(b - g) % 3 == 0) {
      ans = min(ans, calc(b, g, r));
    }
    cout << (ans == 1000000000 ? -1 : ans) << endl;
  }
}
