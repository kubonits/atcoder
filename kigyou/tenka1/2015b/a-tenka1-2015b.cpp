#include <cstdio>
using namespace std;
int main() {
  int a[20];
  a[0] = a[1] = 100;
  a[2] = 200;
  for (int i = 3; i < 20; i++) {
    a[i] = a[i - 1] + a[i - 2] + a[i - 3];
  }
  printf("%d\n", a[19]);
}