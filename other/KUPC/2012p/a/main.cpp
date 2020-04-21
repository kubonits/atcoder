#include <cstdio>
#include <stack>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  scanf("%d%d", &m, &n);
  ll ans, a[4] = {1, 2, 3, 5};
  ans = a[m];
  for (int i = 1; i <= n; i++) {
    if (m == 0) {
      ans++;
    }
    if (m == 1) {
      ans++;
    }
    if (m == 2) {
      ans += 2;
    }
    if (m == 3) {
      ans *= 2LL;
      ans += 3LL;
    }
  }
  printf("%lld\n", ans);
}