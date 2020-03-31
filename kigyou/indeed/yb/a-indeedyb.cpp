#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  int x1, x2, y1, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  printf("%d\n", max(x1, x2) - min(x1, x2) + max(y1, y2) - min(y1, y2) + 1);
}