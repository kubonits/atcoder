#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int h, w, flag;
  char s[100][110], t[100][110];
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
    t[i][w] = '\0';
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      flag = 1;
      for (int k = max(0, i - 1); k < min(h, i + 2); k++) {
        for (int l = max(0, j - 1); l < min(w, j + 2); l++) {
          if (s[k][l] == '.') {
            flag = 0;
          }
        }
      }
      if (flag) {
        t[i][j] = '#';
      } else {
        t[i][j] = '.';
      }
    }
  }
  flag = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        int flag2 = 0;
        for (int k = max(0, i - 1); k < min(h, i + 2); k++) {
          for (int l = max(0, j - 1); l < min(w, j + 2); l++) {
            if (t[k][l] == '#') {
              flag2 = 1;
            }
          }
        }
        if (flag2 == 0) {
          flag = 0;
        }
      }
    }
  }
  if (flag) {
    printf("possible\n");
    for (int i = 0; i < h; i++) {
      printf("%s\n", t[i]);
    }
  } else {
    printf("impossible\n");
  }
}