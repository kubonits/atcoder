#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
  ll h, w, n;
  char s[10][10];
  scanf("%lld%lld%lld", &h, &w, &n);

  printf("%lld\n", (n + max(h, w) - 1) / max(h, w));
}