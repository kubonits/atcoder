#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, k, a[50][1000], b[1000000], p[50], cnt;
int main() {
  vector<int> v[50];
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (; p[i] < (k + cnt) / n; p[i]++) {
      if (b[a[i][p[i]]] == 0) {
        b[a[i][p[i]]] = 1;
        v[i].push_back(a[i][p[i]]);
      } else {
        cnt++;
      }
    }
    if (p[i] == (k + cnt) / n && (k + cnt) % n > i) {
      if (b[a[i][p[i]]] == 0) {
        b[a[i][p[i]]] = 1;
        v[i].push_back(a[i][p[i]]);
      } else {
        cnt++;
      }
      p[i]++;
    }
    int flag = 1;
    while (flag) {
      flag = 0;
      for (int j = 0; j <= i; j++) {
        for (; p[j] < (k + cnt) / n; p[j]++) {
          if (b[a[j][p[j]]] == 0) {
            b[a[j][p[j]]] = 1;
            v[i].push_back(a[j][p[j]]);
          } else {
            cnt++;
            flag = 1;
          }
        }
        if (p[j] == (k + cnt) / n && (k + cnt) % n > j) {
          if (b[a[j][p[j]]] == 0) {
            b[a[j][p[j]]] = 1;
            v[i].push_back(a[j][p[j]]);
          } else {
            cnt++;
          }
          p[j]++;
        }
      }
    }
    sort(v[i].begin(), v[i].end());
    for (int j = 0; j < v[i].size(); j++) {
      printf("%d", v[i][j]);
      if (j != v[i].size() - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}