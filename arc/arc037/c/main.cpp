#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  ll l, r, m, left, right, mid;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  l = 0;
  r = 1000000000000000000;
  while (l <= r) {
    m = (l + r) / 2;
    ll p = n - 1LL, cnt = 0LL;
    for (int i = 0; i < n; i++) {
      while (p >= 0 && a[i] * b[p] >= m) {
        p--;
      }
      cnt += n - 1LL - p;
    }
    if (n * n - cnt < k) {
      l = m + 1LL;
    } else {
      r = m - 1LL;
    }
  }
  cout << r << endl;
}