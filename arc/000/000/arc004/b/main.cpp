#include <algorithm>
#include <cstdio>
using namespace std;
int dp[15000000];
int main() {
  int n, d[500], sum = 0, maxi = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    sum += d[i];
    maxi = max(maxi, d[i]);
  }
  if (sum < 2 * maxi) {
    printf("%d\n", sum);
    printf("%d\n", maxi - (sum - maxi));
  } else {
    printf("%d\n", sum);
    printf("0\n");
  }
}