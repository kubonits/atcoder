#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  char s[8];
  scanf("%s", s);
  if (s[2] == s[3] && s[4] == s[5]) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}