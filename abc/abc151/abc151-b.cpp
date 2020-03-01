#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int main() {
  int n, ans, k, a, m;
  scanf("%d%d%d", &n, &k, &m);
  ans = n * m;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &a);
    ans -= a;
  }
  if (ans <= k) {
    printf("%d\n", max(0, ans));
  } else {
    printf("-1\n");
  }
}