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

ll calc(vector<ll> &x, vector<ll> &y, vector<ll> &z) {
  ll res = 100000000000000000, xmin = 100000000000000000,
     ymin = 100000000000000000;
  int a = 0, b = 0;
  while (a < x.size() && b < y.size()) {
    if (x[a] == y[b]) {
      return 0LL;
    }
    if (x[a] > y[b]) {
      res = min(res, x[a] - y[b]);
      b++;
    } else {
      res = min(res, y[b] - x[a]);
      a++;
    }
  }
  a = 0;
  b = 0;
  for (int i = 0; i < z.size(); i++) {
    while (a < x.size() && x[a] < z[i]) {
      res = min(res, ymin + z[i] - x[a]);
      a++;
    }
    if (a < x.size()) {
      res = min(res, x[a] - z[i] + ymin);
    }
    while (b < y.size() && y[b] < z[i]) {
      res = min(res, xmin + z[i] - y[b]);
      b++;
    }
    if (b < y.size()) {
      res = min(res, y[b] - z[i] + xmin);
    }
    if (a != 0) {
      xmin = min(xmin, z[i] - x[a - 1]);
    }
    if (a < x.size()) {
      xmin = min(xmin, x[a] - z[i]);
    }
    if (b != 0) {
      ymin = min(ymin, z[i] - y[b - 1]);
    }
    if (b < y.size()) {
      ymin = min(ymin, y[b] - z[i]);
    }
  }
  return res;
}

int main() {
  int n;
  ll a;
  char c;
  cin >> n;
  vector<ll> r, g, b;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a >> c;
    if (c == 'R') {
      r.push_back(a);
    } else if (c == 'G') {
      g.push_back(a);
    } else {
      b.push_back(a);
    }
  }
  if (r.size() % 2 == 0 && g.size() % 2 == 0 && b.size() % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  if (r.size() % 2 == 1 && g.size() % 2 == 1) {
    cout << calc(r, g, b) << endl;
  }
  if (b.size() % 2 == 1 && g.size() % 2 == 1) {
    cout << calc(b, g, r) << endl;
  }
  if (r.size() % 2 == 1 && b.size() % 2 == 1) {
    cout << calc(r, b, g) << endl;
  }
}