#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  double y[5], g, h, v[4];
  for (int i = 0; i < 4; i++) {
    printf("? %.12f\n", (double)i);
    fflush(stdout);
    scanf("%lf", &y[i]);
  }
  h = y[0];
  g = y[2] - y[1] + y[3] - y[4];
  g /= 2.0;
  for (int i = 0; i < 4; i++) {
    v[i] = y[i + 1] + g * (double)(i + 1) * (double)(i + 1) / 2.0 - h;
  }
  sort(v, v + 4);
  printf("! %.12f %.12f %.12f\n", h, (v[0] + v[3]) / 2.0, g);
  fflush(stdout);
}