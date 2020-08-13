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

double dis(double x, double y, double xx, double yy) {
  return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

int main() {
  int n, m;
  double x[200], y[200], r[200] = {}, ans = 1000.0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> r[i];
    ans = min(ans, r[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> x[n + i] >> y[n + i];
  }
  for (int i = 0; i < n + m; i++) {
    for (int j = max(n, i + 1); j < m + n; j++) {
      if (i < n) {
        ans = min(ans, dis(x[i], y[i], x[j], y[j]) - r[i]);
      } else {
        ans = min(ans, dis(x[i], y[i], x[j], y[j]) / 2);
      }
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}