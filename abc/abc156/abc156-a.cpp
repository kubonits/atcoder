#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  if (n < 10) {
    r += 100 * (10 - n);
  }
  printf("%d\n", r);
}