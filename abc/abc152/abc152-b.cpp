#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  for (int i = 0; i < max(a, b); i++) {
    printf("%d", min(a, b));
  }
  printf("\n");
}