#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[200000], b[200000];
int main() {
  ll n, k, l, r, mid, cnt;
  cin >> n >> k;
  for (ll i = 0LL; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  l = 0LL;
  r = 1000000000000000LL;
  while (l <= r) {
    mid = (l + r) / 2LL;
    cnt = 0LL;
    for (int i = 0; i < n; i++) {
      if (mid < a[i] * b[n - 1 - i]) {
        cnt += a[i] - mid / b[n - 1 - i];
      }
    }
    if (cnt <= k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}