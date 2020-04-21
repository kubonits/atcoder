#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
ll dpl[200010][2], dpr[200010][2], a[200010], ans;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    dpl[i][0] = dpl[i][1] = dpr[i][0] = dpr[i][1] = -1000000000000000;
  }
  dpl[0][0] = -10000000000000000;
  dpl[1][0] = a[1];
  dpl[0][1] = a[0];
  dpl[1][1] = -10000000000000000;
  dpl[2][0] = a[2];
  for (int i = 0; i < n - 2; i++) {
    if (i % 2) {
      dpl[i + 2][0] = max(dpl[i + 2][0], dpl[i][0] + a[i + 2]);
      if (i + 3 < n) {
        dpl[i + 3][0] = max(dpl[i + 3][0], dpl[i][0] + a[i + 3]);
      }
    } else {
      dpl[i + 2][1] = max(dpl[i + 2][1], dpl[i][1] + a[i + 2]);
      dpl[i + 2][0] = max(dpl[i + 2][0], dpl[i][0] + a[i + 2]);
      if (i + 3 < n) {
        dpl[i + 3][0] = max(dpl[i + 3][0], dpl[i][1] + a[i + 3]);
      }
      if (i + 4 < n) {
        dpl[i + 4][0] = max(dpl[i + 4][0], dpl[i][1] + a[i + 4]);
      }
    }
  }
  printf("%lld\n", max(dpl[n - 1][0], dpl[n - 2][(n + 1) % 2]));
}