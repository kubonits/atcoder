#include <cstdio>
using namespace std;
int main() {
  int n, m, x, y, a[100000], b[100000], t = 0, l = 0, r = 0, cnt = 0;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &x, &y);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  while (l < n && r < m) {
    if (cnt % 2 == 0) {
      while (l < n && a[l] < t) {
        l++;
      }
      if (l >= n) {
        break;
      }
      t = a[l] + x;
      cnt++;
    } else {
      while (r < m && b[r] < t) {
        r++;
      }
      if (r >= m) {
        break;
      }
      t = b[r] + y;
      cnt++;
    }
  }
  printf("%d\n", cnt / 2);
}