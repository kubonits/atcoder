#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int main() {
  int n, x[100], ans = 1000000000, sum;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i <= 100; i++) {
    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += (i - x[j]) * (i - x[j]);
    }
    ans = min(ans, sum);
  }
  printf("%d\n", ans);
}