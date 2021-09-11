#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int main() {
  int n, m, p, a[100010] = {}, flag[100010] = {}, ans = 0, cnt = 0;
  char s[10];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%s", &p, s);
    if (strcmp(s, "AC") == 0) {
      if (flag[p] == 0) {
        cnt++;
        ans += a[p];
      }
      flag[p] = 1;
    } else if (flag[p] == 0) {
      a[p]++;
    }
  }
  printf("%d %d\n", cnt, ans);
}