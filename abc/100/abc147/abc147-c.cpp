#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, a[15], x, y, ans = 0, b[15] = {};
  vector<pair<int, int> > p[15];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j < a[i]; j++) {
      scanf("%d%d", &x, &y);
      x--;
      p[i].push_back({x, y});
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    int flag = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        b[j] = 1;
        flag++;
      } else {
        b[j] = 0;
      }
    }
    for (int j = 0; j < n; j++) {
      if (b[j]) {
        for (int k = 0; k < a[j]; k++) {
          if (b[p[j][k].first] != p[j][k].second) {
            flag = 0;
            break;
          }
        }
      }
    }
    if (flag) {
      ans = max(ans, flag);
    }
  }
  printf("%d\n", ans);
}