#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
  ll t1, t2, a1, a2, b1, b2;
  scanf("%lld%lld", &t1, &t2);

  scanf("%lld%lld", &a1, &a2);
  scanf("%lld%lld", &b1, &b2);
  if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
    printf("infinity\n");
  } else if (a1 > b1 && (a1 - b1) * t1 + (a2 - b2) * t2 > 0 ||
             a1 < b1 && (a1 - b1) * t1 + (a2 - b2) * t2 < 0) {
    printf("0\n");
  } else {
    double t;
    t = abs(a1 - b1) * t1;
    t /= (double)abs(a2 - b2);
    /*t *= -1;
    t += t2;*/
    printf("%f\n", (min(a2, b2) * t));
    double dis = abs((a1 - b1) * t1 + (a2 - b2) * t2);
    printf("%.0f\n", floor(1.0 + (abs(a1 - b1) * t1 + min(a2, b2) * t) / dis));
  }
}
