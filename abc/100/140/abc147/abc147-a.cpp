#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a + b + c > 21) {
    printf("bust\n");
  } else {
    printf("win\n");
  }
}