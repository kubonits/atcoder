#include <algorithm>
#include <cmath>
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

int main() {
  int n;
  cin >> n;
  vector<double> x(n), w(n);
  double left, right, l, r, mid;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> w[i];
  }
  left = 0;
  right = 1e15;
  for (int j = 0; j < 1000; j++) {
    mid = (left + right) / 2.0;
    l = x[0];
    r = x[n - 1];
    for (int i = 0; i < n; i++) {
      l = max(l, x[i] - mid / w[i]);
      r = min(r, x[i] + mid / w[i]);
    }
    if (l <= r) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << fixed << setprecision(10) << l << endl;
}