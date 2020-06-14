#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

double comb(double x, double y) {
  double res = 1.0;
  for (double i = 1.0; i <= y; i += 1.0) {
    res *= (x - y + i) / i;
  }
  return res;
}
double a[101][101], dp[101] = {}, t[101], dp2[101] = {}, x[101], z[101], ans;
void calc(int n, double sum, double pro) {
  if (n == 1) {
    ans += sum * pro;
    return;
  }
  for (int i = 1; i <= n / 2; i++) {
    calc(i, sum + x[n], pro * a[n][i] / z[n]);
  }
}

int main() {
  int flag[101] = {};
  double n;
  cin >> n;
  t[0] = 1.0;
  for (int i = 1; i <= n; i++) {
    t[i] = t[i - 1] / 3.0;
  }
  dp2[(int)n] = 1.0;
  flag[(int)n] = 1;
  for (int i = n; i >= 2; i--) {
    if (flag[i]) {
      double y = 0.0;
      for (int j = i + 1; j <= n; j++) {
        dp[i] += (dp[j] + x[j]) * a[j][i] * dp2[j];
        y += a[j][i] * dp2[j];
      }
      if (y != 0.0) {
        dp[i] /= y;
      }
      for (int j = 0; j <= i; j++) {
        for (int k = 0; j + k <= i; k++) {
          int mini = 100;
          if (k && j && i - j - k) {
            mini = min(j, min(k, i - j - k));
          } else if (j && k) {
            mini = min(j, k);
          } else if (j && i - j - k) {
            mini = min(j, i - j - k);
          } else if (k && i - j - k) {
            mini = min(k, i - j - k);
          }
          if (j == k && j == i - j - k) {
            mini = 100;
          }
          a[i][mini] += comb((double)i, (double)j) * comb(i - j, k);
          flag[mini] = 1;
        }
      }
      x[i] = 3.0;
      if (i % 3 == 0 && i >= 3) {
        x[i] += comb((double)i, (double)i / 3.0) *
                comb(2.0 * (double)i / 3.0, (double)i / 3.0);
      }
      x[i] *= t[i];
      x[i] = 1.0 / (1.0 - x[i]);
      for (int j = 1; j <= i / 2; j++) {
        z[i] += a[i][j];
      }
      // ans += (dp[i] + x[i]) * a[i][1] / y * dp2[i];
      /*for (int j = 2; j <= i / 2; j++) {
        dp2[j] += a[i][j] / y * dp2[i];
      }*/
    }
  }
  calc(n, 0.0, 1.0);
  cout << fixed << setprecision(9) << ans << endl;
}