#include <cstdio>
using namespace std;
int main() {
  int n, a[32] = {1, 1, 1, 2, 1, 2, 1, 5,  2, 2, 1, 5, 1, 2, 1, 14,
                  1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  scanf("%d", &n);
  printf("%d\n", a[n - 1]);
}