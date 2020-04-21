#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll n, a[100000], l1, l2, r1, r2, mid1, mid2;
  ll m, ans = 0, sum[100001];
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  l1 = 0;
  r1 = 300000;
  sum[n] = 0;
  sort(a, a + n);
  for (ll i = n - 1; i >= 0; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  while (l1 <= r1) {
    mid1 = (l1 + r1) / 2;
    ll cnt = 0LL;
    for (ll i = 0; i < n; i++) {
      l2 = 0;
      r2 = n - 1;
      while (l2 <= r2) {
        mid2 = (l2 + r2) / 2;
        if (a[mid2] + a[i] >= mid1) {
          r2 = mid2 - 1;
        } else {
          l2 = mid2 + 1;
        }
      }
      cnt += (ll)(n - l2);
    }
    if (cnt <= m) {
      r1 = mid1 - 1;
    } else {
      l1 = mid1 + 1;
    }
  }
  ll cnt = 0LL;
  for (ll i = 0; i < n; i++) {
    l2 = 0;
    r2 = n - 1;
    while (l2 <= r2) {
      mid2 = (l2 + r2) / 2;
      if (a[mid2] + a[i] >= l1) {
        r2 = mid2 - 1;
      } else {
        l2 = mid2 + 1;
      }
    }
    cnt += (ll)(n - l2);
    ans += sum[l2];
    ans += (ll)((n - l2) * a[i]);
  }
  printf("%lld\n", ans + (ll)(m - cnt) * (ll)(r1));
}