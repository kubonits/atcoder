#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int x, y, ans = 0;
  scanf("%d %d", &x, &y);
  if (x == 3) {
    ans += 100000;
  } else if (x == 2) {
    ans += 200000;
  } else if (x == 1) {
    ans += 300000;
  }
  if (y == 3) {
    ans += 100000;
  } else if (y == 2) {
    ans += 200000;
  } else if (y == 1) {
    ans += 300000;
  }
  if (x == 1 && y == 1) {
    ans += 400000;
  }
  printf("%d\n", ans);
}
