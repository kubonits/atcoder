#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int g = gcd(i, j);
      for (int k = 1; k <= n; k++) {
        ans += gcd(g, k);
      }
    }
  }
  printf("%d\n", ans);
}