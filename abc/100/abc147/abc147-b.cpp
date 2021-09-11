#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
  int n, ans = 0;
  char s[110];
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
}