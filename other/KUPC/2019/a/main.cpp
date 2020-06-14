#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, x, a[1000], maxi = 0, ans = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] + x >= maxi) {
      ans++;
    }
  }
  cout << ans << endl;
}