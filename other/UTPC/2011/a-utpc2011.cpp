#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int n, m, a[20][20], ans = 0;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      cnt += a[i][j];
    }
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
}