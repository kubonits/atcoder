#include <algorithm>
#include <iostream>
using namespace std;
int n, h[300000], l[300000], r[300000], ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  l[0] = 0;
  for (int i = 1; i < n; i++) {
    if (h[i] > h[i - 1]) {
      l[i] = l[i - 1];
    } else {
      l[i] = i;
    }
  }
  r[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (h[i] > h[i + 1]) {
      r[i] = r[i + 1];
    } else {
      r[i] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, r[i] - l[i] + 1);
  }
  cout << ans << endl;
}