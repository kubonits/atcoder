#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int x, ans = 0;
  scanf("%d", &x);
  ans += x / 500 * 1000 + x % 500 / 5 * 5;
  printf("%d\n", ans);
}