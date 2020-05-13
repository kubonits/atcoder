#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[200000];
int main() {
  ll n, k, l, r, mid, cnt, left, right, mm;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  l = -1000000000000000010;
  r = 1000000000000000010;
  cnt = 0LL;
  while (l <= r) {
    cnt = 0LL;
    mid = (l + r) / 2LL;
    for (ll i = 0LL; i < n; i++) {
      left = i + 1LL;
      right = n - 1LL;
      if (a[i]) {
        while (left <= right) {
          mm = (left + right) / 2LL;
          if (mid > a[i] * a[mm]) {
            if (a[i] > 0) {
              left = mm + 1LL;
            } else {
              right = mm - 1LL;
            }
          } else if (a[i] > 0) {
            right = mm - 1LL;
          } else {
            left = mm + 1LL;
          }
        }
        if (a[i] > 0) {
          cnt += right - i;
        } else {
          cnt += n - left;
        }
      } else if (0 < mid) {
        cnt += n - i - 1LL;
      }
    }
    if (cnt < k) {
      l = mid + 1LL;
    } else {
      r = mid - 1LL;
    }
  }
  cout << r << endl;
}