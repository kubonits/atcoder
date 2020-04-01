#include <cstdio>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if ((n - 1) / 20 % 2) {
    printf("%d\n", 20 - (n - 1) % 20);
  } else {
    printf("%d\n", (n - 1) % 20 + 1);
  }
}