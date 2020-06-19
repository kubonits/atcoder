#include <iostream>
using namespace std;
int main() {
  int n, p, a[40], ans = 0;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (p >= a[i]) {
      p -= a[i];
      ans++;
    } else {
      break;
    }
  }
  cout << ans << endl;
}