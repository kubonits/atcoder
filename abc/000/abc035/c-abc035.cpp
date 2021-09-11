#include <cstdio>
using namespace std;
int n, q, l, r, a[200010], sum[200010];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    a[l]++;
    a[r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
    printf("%d", sum[i] % 2);
  }
  printf("\n");
}