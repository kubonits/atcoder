#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, a[100000], cnt[100010] = {};
  priority_queue<int> q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  if (n == 2) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == n - 1) {
      printf("%d ", i);
      if (i == 1 && a[0] != 2) {
        for (int j = 2; j <= n; j++) {
          printf("%d ", j);
        }
        printf("\n");
        return 0;
      } else if (i == 1 && a[0] == 2) {
        printf("3 2 ");
        for (int j = 4; j <= n; j++) {
          printf("%d ", j);
        }
        printf("\n");
        return 0;
      } else if (i == 2 && a[1] != 1) {
        printf("1 ");
        for (int j = 3; j <= n; j++) {
          printf("%d ", j);
        }
        printf("\n");
        return 0;
      } else if (i == 2 && a[1] == 1) {
        printf("3 1 ");
        for (int j = 4; j <= n; j++) {
          printf("%d ", j);
        }
        printf("\n");
        return 0;
      } else if (a[i - 1] != 1) {
        printf("1 ");
        for (int j = 2; j <= n; j++) {
          if (j != i) {
            printf("%d ", j);
          }
        }
        printf("\n");
        return 0;
      } else if (a[i - 1] == 1) {
        printf("2 1 ");
        for (int j = 3; j <= n; j++) {
          if (j != i) {
            printf("%d ", j);
          }
        }
        printf("\n");
        return 0;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    q.push(-i);
  }
  printf("1 ");
  int x = 1;
  int y = -q.top();
  q.pop();
  for (int i = 0; i < n - 1; i++) {
    if (a[x - 1] != y) {
      printf("%d ", y);
      x = y;
      y = -q.top();
      q.pop();
    } else {
      printf("%d ", -q.top());
      x = -q.top();
      q.pop();
    }
  }
  printf("\n");
}