#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  double pi = acos(-1), r, d, ans;
  scanf("%lf%lf", &r, &d);
  ans = r * r * pi * 2 * pi * d;
  printf("%f\n", ans);
}