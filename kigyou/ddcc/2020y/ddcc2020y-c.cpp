#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
int h, w, ans[300][300], cnt = 0, p = 0, k, sum[100001];
char s[300][310];
int main() {
  scanf("%d%d%d", &h, &w, &k);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        cnt++;
        ans[i][j] = cnt;
        for (int k = j - 1; k >= 0; k--) {
          if (ans[i][k] == 0) {
            ans[i][k] = cnt;
          } else {
            break;
          }
        }
        for (int k = j + 1; k < w; k++) {
          if (s[i][k] == '.') {
            ans[i][k] = cnt;
          } else {
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < h; i++) {
    if (ans[i][0] == 0) {
      for (int j = i + 1; j < h; j++) {
        if (ans[j][0]) {
          p = j;
          break;
        }
      }
      for (int j = i; j < p; j++) {
        for (int k = 0; k < w; k++) {
          ans[j][k] = ans[p][k];
        }
      }
    }
  }
  p = h;
  for (int i = h - 1; i >= 0; i--) {
    if (ans[i][0] == 0) {
      for (int j = i - 1; j >= 0; j--) {
        if (ans[j][0]) {
          p = j;
          break;
        }
      }
      for (int j = i; j > p; j--) {
        for (int k = 0; k < w; k++) {
          ans[j][k] = ans[p][k];
        }
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}
