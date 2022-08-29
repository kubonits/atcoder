#include <cstdio>
using namespace std;
int main() {
  int n, k, a[300000], ans = 0, cnt = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  cnt = 1;
  if (k == 1) {
    ans++;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      cnt++;

    } else {
      cnt = 1;
    }
    if (cnt >= k) {
      ans++;
    }
  }
  printf("%d\n", ans);
}