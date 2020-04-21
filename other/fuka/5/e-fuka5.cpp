#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
int n, x[500000];
pair<double, double> y[500000];
int main() {
  scanf("%d", &n);
  while (n) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
    }
    y[n - 1].first = 0;
    y[n - 1].second = 0;
    for (int i = n - 2; i >= 0; i--) {
      y[i].first = 0;
      y[i].second = 0;
      if (x[i] == -1) {
        y[i].first = 0;
        y[i].second = 1;
      } else if (x[i]) {
        y[i] = y[min(n - 1, i + x[i])];
      } else {
        for (int j = 1; j <= 6; j++) {
          y[i].first += (y[min(n - 1, i + j)].first + 1.0) / 6;
          y[i].second += (y[min(n - 1, i + j)].second) / 6;
        }
      }
    }
    printf("%.8f\n", y[0].first / (1 - y[0].second));
    scanf("%d", &n);
  }
}