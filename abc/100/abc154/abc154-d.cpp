#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  double a[200000], ans = 0.0, sum = 0.0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &a[i]);
  }
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }
  ans = sum;
  for (int i = k; i < n; i++) {
    sum += a[i];
    sum -= a[i - k];
    ans = max(ans, sum);
  }
  ans += k;
  printf("%f\n", ans / 2);
}