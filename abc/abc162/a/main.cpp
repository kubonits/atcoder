#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n / 100 == 7 || n / 10 % 10 == 7 || n % 10 == 7) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}