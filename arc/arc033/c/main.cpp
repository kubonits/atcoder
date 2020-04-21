#include <cstdio>
using namespace std;

int bit[200001], n;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}

int add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += (i & -i);
  }
}

int main() {
  int q, x, t, left, right, mid;
  n = 200000;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &t, &x);
    if (t == 1) {
      add(x, 1);
    } else {
      left = 0;
      right = 200000;
      while (left <= right) {
        mid = (left + right) / 2;
        if (sum(mid) >= x) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      printf("%d\n", left);
      add(left, -1);
    }
  }
}