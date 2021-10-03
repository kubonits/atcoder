#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n, a[200010];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}