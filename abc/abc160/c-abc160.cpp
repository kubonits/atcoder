#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int k, n, a[200000], ans = 0;
  scanf("%d%d", &k, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, (k + a[(i + 1) % n] - a[i]) % k);
  }
  if (n == 2) {
    printf("%d\n", min(k - ans, ans));
  } else {
    printf("%d\n", k - ans);
  }
}