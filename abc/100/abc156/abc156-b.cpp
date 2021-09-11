#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int main() {
  int n, k, cnt = 0;
  scanf("%d%d", &n, &k);
  while (n) {
    cnt++;
    n /= k;
  }
  printf("%d\n", cnt);
}