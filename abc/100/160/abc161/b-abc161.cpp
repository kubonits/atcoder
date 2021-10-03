#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int m, n, a[1000], sum = 0, cnt = 0;
  ;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum % (4 * m) == 0 && a[i] >= sum / (4 * m)) {
      cnt++;
    } else if (sum % (4 * m) && a[i] > sum / (4 * m)) {
      cnt++;
    }
  }
  if (cnt >= m) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}