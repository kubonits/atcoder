#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, m, s, c, x[4] = {-1, -1, -1, -1};
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &s, &c);
    if (s == 1 && c == 0 && n > 1) {
      printf("-1\n");
      return 0;
    } else if (x[s] == -1) {
      x[s] = c;
    } else if (x[s] != c) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] == -1 && i == 1 && n > 1) {
      printf("1");
    } else if (x[i] == -1) {
      printf("0");
    } else {
      printf("%d", x[i]);
    }
  }
  printf("\n");
}