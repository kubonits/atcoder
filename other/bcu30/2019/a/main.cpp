#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, a[100], k, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (i < k) {
      ans += a[n - 1 - i];
    } else {
      ans += 2 * a[n - 1 - i];
    }
  }
  cout << ans << endl;
}