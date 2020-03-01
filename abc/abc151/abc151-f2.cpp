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
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &x[i], &y[i]);
    x[i] += 1.0;
  }
  double cx = 500.0, cy = 500.0, r, left = 0.0, right, alpha = 1e2;
  for (int i = 0; i < 5000000; i++) {
    double dx = (sqrt(calc(cx + 1e-7, cy)) - sqrt(calc(cx, cy))) / 1e-7;
    double dy = (sqrt(calc(cx, cy + 1e-7)) - sqrt(calc(cx, cy))) / 1e-7;
    cx -= alpha * dx;
    cy -= alpha * dy;
    alpha *= 0.9999;
  }
  printf("%.10f\n", sqrt(calc(cx, cy)));
}