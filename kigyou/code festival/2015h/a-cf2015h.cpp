#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
ll l[100001], r[100001], sl[100001], sr[100001];

int main() {
  int n;
  ll a[100000], ans = 1000000000000000000;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  l[1] = a[0];
  r[n - 2] = a[n - 1];
  for (int i = 2; i < n; i++) {
    l[i] = l[i - 1] + a[i - 1] + 1LL;
  }
  for (int i = n - 3; i >= 0; i--) {
    r[i] = r[i + 1] + a[i + 1] + 1LL;
  }
  sl[0] = 0;
  sl[1] = a[0];
  sr[n - 1] = 0;
  sr[n - 2] = a[n - 1];
  for (int i = 0; i < n; i++) {
    sl[i] = sl[i - 1] + l[i];
  }
  for (int i = n - 3; i >= 0; i--) {
    sr[i] = sr[i + 1] + r[i];
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans = min(ans, sl[i] + sr[i]);
    }
  }
  printf("%lld\n", ans);
}