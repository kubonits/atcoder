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
  int n;
  double m, s, ans = 0.0;
  cin >> n >> m >> s;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    // cout << i + 1 << " " << ans << endl;
    double sum = 0.0, ave = 0.0, p = i;
    for (int j = i; j >= 0; j--) {
      sum += a[j];
      if (ave < sum / (double)(i - j + 1)) {
        ave = max(ave, sum / (double)(i - j + 1));
        p = j;
      }
    }
    if ((double)(i - p + 1) * m >= s) {
      cout << fixed << setprecision(15) << ans + s * ave << endl;
      return 0;
    } else {
      ans += (double)(i - p + 1) * ave * m;
      s -= m * (double)(i - p + 1);
      i = p;
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
}
