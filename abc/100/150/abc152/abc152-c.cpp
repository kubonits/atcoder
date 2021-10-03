#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n, p[200000], mini[200000], ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  mini[0] = p[0];
  for (int i = 1; i < n; i++) {
    mini[i] = min(mini[i - 1], p[i]);
  }
  for (int i = 0; i < n; i++) {
    if (mini[i] == p[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
}