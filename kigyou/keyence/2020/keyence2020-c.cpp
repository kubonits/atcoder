#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, k, s;
  scanf("%d%d%d", &n, &k, &s);
  if (s != 1e9) {
    for (int i = 0; i < n; i++) {
      if (i < k) {
        printf("%d ", s);
      } else {
        printf("%d ", s + 1);
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (i < k) {
        printf("%d ", s);
      } else {
        printf("%d ", s - 1);
      }
    }
  }
  printf("\n");
}