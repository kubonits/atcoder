#include <cstdio>
using namespace std;

int counter = 0;
int gcd(int a, int b) {
  if (b == 0) return a;
  counter++;
  return gcd(b, a % b);
}

int main() {
  int k, a[42];
  scanf("%d", &k);
  a[0] = a[1] = 1;
  for (int i = 2; i <= k + 1; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  printf("%d %d\n", a[k + 1], a[k]);
}