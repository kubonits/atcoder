#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  double l;
  cin >> n >> l;
  vector<double> x(n + 2), dp(n + 3), v(n + 2), d(n + 2);
  cin >> v[0] >> d[0];
  x[0] = 0.0;
  x[n + 1] = l;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i] >> d[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (x[i] > x[j]) {
        swap(x[i], x[j]);
        swap(v[i], v[j]);
        swap(d[i], d[j]);
      }
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = 1000000000.0;
  }
  dp[0] = 0.0;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n + 1; j++) {
      if (x[i] + d[i] >= x[j]) {
        dp[j] = min(dp[j], dp[i] + (x[j] - x[i]) / v[i]);
      }
    }
  }
  if (dp[n + 1] != 1000000000.0) {
    cout << fixed << setprecision(7) << dp[n + 1] << endl;
  } else {
    cout << "impossible" << endl;
  }
}