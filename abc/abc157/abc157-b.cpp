#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int a[3][3], b[10], n, c[3][3] = {}, flag = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (b[i] == a[j][k]) {
          c[j][k] = 1;
        }
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (c[i][0] && c[i][1] && c[i][2]) {
      flag = 1;
    }
    if (c[0][i] && c[1][i] && c[2][i]) {
      flag = 1;
    }
  }
  if (c[0][0] && c[1][1] && c[2][2]) {
    flag = 1;
  }
  if (c[0][2] && c[1][1] && c[2][0]) {
    flag = 1;
  }
  if (flag) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}