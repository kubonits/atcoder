#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int n, sum = 0, ans = 500, t[4];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
    sum += t[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    int aa = 0;
    for (int j = 0; j < n; j++) {
      if ((1 << j) & i) {
        aa += t[j];
      }
    }
    ans = min(ans, max(sum - aa, aa));
  }
  printf("%d\n", ans);
}