#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll n, ans = 0LL;
  scanf("%lld", &n);
  for (ll i = 1LL; i <= n; i++) {
    if (i % 3LL && i % 5LL) {
      ans += i;
    }
  }
  printf("%lld\n", ans);
}