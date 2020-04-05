#include <cstdio>
using namespace std;
int main() {
  int s, r, l;
  scanf("%d%d%d", &s, &l, &r);
  if (s < l) {
    printf("%d\n", l);
  } else if (s > r) {
    printf("%d\n", r);
  } else {
    printf("%d\n", s);
  }
}