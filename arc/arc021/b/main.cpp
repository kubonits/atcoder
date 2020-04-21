#include <cstdio>
using namespace std;
int main() {
  int n, b[100000], sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    sum ^= b[i];
  }
  if (sum) {
    printf("-1\n");
    return 0;
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    printf("%d\n", sum);
    sum ^= b[i];
  }
}