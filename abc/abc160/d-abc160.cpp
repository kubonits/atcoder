#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int n, x, y, g[2001][2001], ans[2000] = {};
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans[min(j - i, max(x, i) - min(x, i) + max(y, j) - min(y, j) + 1)]++;
    }
  }
  for (int i = 1; i < n; i++) {
    printf("%d\n", ans[i]);
  }
}