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
  cin >> n;
  vector<double> a(n), b(n), sum(n + 1);
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sum[i + 1] = a[i] / b[i] + sum[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum[i + 1] <= sum[n] / 2.0) {
      ans += a[i];
    } else if (sum[i + 1] > sum[n] / 2.0 && sum[i] <= sum[n] / 2.0) {
      ans += b[i] * (sum[n] / 2.0 - sum[i]);
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
}
