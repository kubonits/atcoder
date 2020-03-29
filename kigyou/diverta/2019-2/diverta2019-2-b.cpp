#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int n, x[50], y[50], p, q, ans = 50;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        p = x[i] - x[j];
        q = y[i] - y[j];
      }
      int cnt = 0;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if (k != l && x[k] - x[l] == p && y[k] - y[l] == q) {
            cnt++;
          }
        }
      }
      ans = min(ans, n - cnt);
    }
  }
  printf("%d\n", max(1, ans));
}