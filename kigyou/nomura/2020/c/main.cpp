#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll a[100001], n, l[100001], r[100001], ans;

int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  if (a[0] > 1) {
    cout << -1 << endl;
    return 0;
  }
  l[n] = r[n] = a[n];
  for (int i = n - 1; i >= 0; i--) {
    l[i] = a[i] + (l[i + 1] + 1) / 2;
    r[i] = a[i] + r[i + 1];
  }
  l[0] = r[0] = 1;
  for (int i = 0; i < n; i++) {
    ans += r[i];
    if (l[i] - a[i] > r[i + 1] || (r[i] - a[i]) * 2 < l[i + 1]) {
      cout << -1 << endl;
      return 0;
    }
    l[i + 1] = max(l[i + 1], l[i] - a[i]);
    r[i + 1] = min(r[i + 1], (r[i] - a[i]) * 2);
  }
  cout << ans + a[n] << endl;
}