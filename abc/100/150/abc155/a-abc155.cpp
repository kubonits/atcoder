#include <cstdio>
using namespace std;
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a == b && b == c || (a != b && b != c && a != c)) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
}