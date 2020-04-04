#include <cstdio>
using namespace std;
int main() {
  int a, b, c, x[128] = {}, flag = 0;
  scanf("%d%d%d", &a, &b, &c);
  for (int i = 1; i <= 127; i++) {
    if (i % 3 == a && i % 5 == b && i % 7 == c) {
      printf("%d\n", i);
      flag = 1;
    }
  }
}