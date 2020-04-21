#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int n, k, x[100], ans;
  scanf("%d%d", &n, &k);
  while (n || k) {
    ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
    }
    sort(x, x + n);
    for (int i = 0; i < k; i++) {
      ans += x[i];
    }
    printf("%d\n", ans);
    scanf("%d%d", &n, &k);
  }
}