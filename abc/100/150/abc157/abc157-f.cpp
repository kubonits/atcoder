#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

int n, k;
double c[60], x[60], y[60];

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double calc(double xx, double yy) {
  vector<double> v;
  double res = 0.0;
  for (int i = 0; i < n; i++) {
    v.push_back(c[i] * dis(xx, yy, x[i], y[i]));
  }
  sort(v.begin(), v.end());
  return v[k - 1];
}
int main() {
  double ans = 1000000000.0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf%lf", &x[i], &y[i], &c[i]);
  }
  for (double i = -1000.0; i <= 1000.0; i += 200.0) {
    for (double j = -1000.0; j <= 1000.0; j += 200.0) {
      double xx = i;
      double yy = j;
      double alpha = 1.0;
      ans = min(ans, calc(xx, yy));
      while (alpha > 0.01) {
        double dx = (calc(xx + 0.00000001, yy) - calc(xx - 0.00000001, yy)) /
                    0.00000002;
        double dy = (calc(xx, yy + 0.00000001) - calc(xx, yy - 0.00000001)) /
                    0.00000002;
        xx -= alpha * dx;
        yy -= alpha * dy;
        ans = min(ans, calc(xx, yy));
        alpha *= 0.997;
      }
    }
  }
  printf("%lf\n", ans);
}
