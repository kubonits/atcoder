#include <cstdio>
using namespace std;
int main() {
  int n, k, a;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    k -= a;
    if (k <= 0) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
}