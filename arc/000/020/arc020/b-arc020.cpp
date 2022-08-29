#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int n, c, a[1000], ans = 100000000, y;
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i != j) {
        y = 0;
        for (int k = 0; k < n; k++) {
          if (k % 2 == 0 && a[k] != i) {
            y += c;
          } else if (k % 2 == 1 && a[k] != j) {
            y += c;
          }
        }
        ans = min(ans, y);
      }
    }
  }
  printf("%d\n", ans);
}