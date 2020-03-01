#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, t[50], ans = 0;
  char s[50][110], x[110];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    scanf("%d", &t[i]);
    ans+=t[i];
  }
  scanf("%s", x);
  for (int i = 0; i < n; i++) {
    ans -= t[i];
    if (strcmp(s[i], x) == 0) {
      break;
    }
  }
  printf("%d\n", ans);
}