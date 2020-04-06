#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
  ll s, x[3], y[3];
  scanf("%lld", &s);
  x[0] = y[0] = 0LL;
  x[1] = 1000000000LL;
  y[1] = 1LL;
  x[2] = (x[1] - s % x[1]) % x[1];
  y[2] = (s + x[2]) / x[1];
  for (int i = 0; i < 3; i++) {
    printf("%lld %lld ", x[i], y[i]);
  }
  printf("\n");
}