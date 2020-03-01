#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, x[100000], l[100000], ans = 0, y = -2e9;
  pair<int, int> p[100000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &l[i]);
    p[i] = {x[i] + l[i], x[i] - l[i]};
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    if (y <= p[i].second) {
      ans++;
      y = p[i].first;
    }
  }
  printf("%d\n", ans);
}