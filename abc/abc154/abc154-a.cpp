#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int a, b;
  char s[100], t[100], u[100];
  scanf("%s%s", s, t);
  scanf("%d%d", &a, &b);
  scanf("%s", u);
  if (strcmp(s, u) == 0) {
    printf("%d %d\n", a - 1, b);
  } else {
    printf("%d %d\n", a, b - 1);
  }
}