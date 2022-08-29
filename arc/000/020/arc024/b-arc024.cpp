#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int n, a[100000], cnt = 0, ans = 0, cnt2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) {
      cnt++;
    } else {
      cnt2++;
    }
  }
  if (cnt == n || cnt2 == n) {
    printf("-1\n");
    return 0;
  }
  cnt = 0;
  cnt2 = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (a[i % n]) {
      cnt++;
      ans = max(ans, cnt2);
      cnt2 = 0;
    } else {
      cnt2++;
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  if (ans < 3) {
    printf("1\n");
  } else {
    printf("%d\n", (ans + 1) / 2);
  }
}