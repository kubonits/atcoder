#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n;
double x[50], y[50];
double dis(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double calc(double xx, double yy) {
  double res = 0.0;
  for (int i = 0; i < n; i++) {
    res = max(res, dis(xx, yy, x[i], y[i]));
  }
  return res;
}
int main() {
  vector<pair<double, double> > v;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &x[i], &y[i]);
  }
  double r, left = 0.0, right;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      left = max(left, sqrt(dis(x[i], y[i], x[j], y[j])) / 2.0);
    }
  }
  left -= 1e-7;
  right = 20000.0;
  while (right - left >= 1e-10) {
    int flag = 0;
    r = (right + left) / 2;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double h = sqrt(r * r - dis(x[i], y[i], x[j], y[j]) / 4.0);
        double dx, dy;
        dx = h * (y[i] - y[j]) / sqrt(dis(x[i], y[i], x[j], y[j]));
        dy = -h * (x[i] - x[j]) / sqrt(dis(x[i], y[i], x[j], y[j]));
        int flag2 = 1;
        for (int k = 0; k < n; k++) {
          if (k != i && k != j &&
              dis((x[i] + x[j]) / 2.0 + dx, (y[i] + y[j]) / 2.0 + dy, x[k],
                  y[k]) > r * r + 1e-7) {
            flag2 = 0;
          }
        }
        if (flag2) {
          flag = 1;
        }
        flag2 = 1;
        for (int k = 0; k < n; k++) {
          if (k != i && k != j &&
              dis((x[i] + x[j]) / 2.0 - dx, (y[i] + y[j]) / 2.0 - dy, x[k],
                  y[k]) > r * r + 1e-7) {
            flag2 = 0;
          }
        }
        if (flag2) {
          flag = 1;
        }
      }
    }
    if (flag) {
      right = r;
    } else {
      left = r;
    }
  }
  printf("%.10f\n", left);
}