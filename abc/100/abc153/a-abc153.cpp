#include <cstdio>
using namespace std;
int main() {
  int h, a;
  scanf("%d%d", &h, &a);
  if (h % a) {
    printf("%d\n", h / a + 1);
  } else {
    printf("%d\n", h / a);
  }
}