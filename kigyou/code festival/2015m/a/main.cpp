#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll n, k, m, r, s[100], sum = 0LL;
  cin >> n >> k >> m >> r;
  sum = k * r;
  if (n == 1 && k == 1 && m >= r) {
    cout << r << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> s[i];
  }
  sort(s, s + n - 1);
  for (int i = 0; i < min(k, n - 1LL) && n - 2 - i >= 0; i++) {
    sum -= s[n - 2 - i];
  }
  if (sum <= 0) {
    cout << 0 << endl;
  } else if (k == n && sum <= m) {
    cout << sum << endl;
  } else if (k == n) {
    cout << -1 << endl;
  } else if (sum + s[n - k - 1] <= m) {
    cout << sum + s[n - k - 1] << endl;
  } else {
    cout << -1 << endl;
  }
}