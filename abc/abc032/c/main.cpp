#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, k, a[100000], ans;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      cout << n << endl;
      return 0;
    }
  }
  ll l = 0, r = 0, b = 1LL;
  for (int i = 0; i < n; i++) {
    if (r < i) {
      r = i;
      b = 1LL;
    }

    while (r < n && b * a[r] <= k) {
      b *= a[r];
      r++;
    }
    b /= a[i];
    ans = max(ans, r - i);
  }
  cout << ans << endl;
}