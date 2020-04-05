#include <cstdio>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) {
    return x;
  }
  return gcd(y, x % y);
}

int n, q, a[100000], s[100000], b[100001];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i) {
      b[i + 1] = gcd(a[i], b[i]);
    } else {
      b[i + 1] = a[i];
    }
  }
  for (int i = 0; i < q; i++) {
    int l = 1;
    int r = n;
    scanf("%d", &s[i]);
    if (gcd(s[i], b[n]) != 1) {
      printf("%d\n", gcd(s[i], b[n]));
    } else {
      while (l <= r) {
        int mid = (l + r) / 2;
        if (gcd(b[mid], s[i]) == 1) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      printf("%d\n", l);
    }
  }
}