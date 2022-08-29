#include <cstdio>
using namespace std;
int main() {
  char b[500][510];
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", b[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ans = 0;
      if (i > 0 && j > 0 && i < n - 1 && j < m - 1) {
        while (b[i - 1][j] > '0' && b[i + 1][j] > '0' && b[i][j - 1] > '0' &&
               b[i][j + 1] > '0') {
          ans++;
          b[i - 1][j]--;
          b[i + 1][j]--;
          b[i][j - 1]--;
          b[i][j + 1]--;
        }
      }
      printf("%d", ans);
    }
    printf("\n");
  }
}