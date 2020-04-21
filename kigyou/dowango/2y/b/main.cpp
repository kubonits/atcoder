#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int n, k[100000], l[100000];
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &k[i]);
  }
  l[0] = k[0];
  l[n - 1] = k[n - 2];
  for (int i = 1; i < n - 1; i++) {
    l[i] = min(k[i], k[i - 1]);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", l[i]);
  }
  printf("\n");
}