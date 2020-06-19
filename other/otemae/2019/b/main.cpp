#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, m, k, x, a[2001] = {};
  cin >> m >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  int cnt, ans = 0;
  for (int i = 1; i <= m; i++) {
    cnt = a[i];
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0 && a[i - j] || i + j <= m && a[i + j]) {
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}