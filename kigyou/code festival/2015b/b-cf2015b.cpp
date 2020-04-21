#include <cstdio>
using namespace std;

int x[100001];

int main() {
  int n, m, a;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    x[a]++;
  }
  for (int i = 0; i <= m; i++) {
    if (x[i] >= (n / 2 + 1)) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("?\n");
}