#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int a[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, n;
  int m, d, b[13][32] = {}, l, flag, ans = 0;
  char s[10];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    m = 0;
    d = 0;
    l = strlen(s);
    flag = 0;
    for (int j = 0; j < l; j++) {
      if (s[j] == '/') {
        flag = 1;
      } else if (flag) {
        d *= 10;
        d += s[j] - '0';
      } else {
        m *= 10;
        m += s[j] - '0';
      }
    }
    b[m][d] = 1;
  }
  int cnt = 0;
  flag = 0;
  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= a[i]; j++) {
      if (b[i][j] == 1 && (cnt % 7 == 0 || cnt % 7 == 6)) {
        flag++;
      } else if (cnt % 7 == 0 || cnt % 7 == 6) {
        b[i][j] = 1;
      } else if (flag && b[i][j] == 0) {
        flag--;
        b[i][j] = 1;
      }
      cnt++;
    }
  }
  cnt = 0;
  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= a[i]; j++) {
      if (b[i][j]) {
        cnt++;
        ans = max(ans, cnt);
      } else {
        cnt = 0;
      }
    }
  }
  printf("%d\n", ans);
}