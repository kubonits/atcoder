#include <iostream>
using namespace std;
int main() {
  int n, a[200000], ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (n && !a[n - 1]) {
    n--;
  }
  if (n) {
    ans = 1;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1] && (a[i] || i != n - 1)) {
      ans++;
    }
  }
  cout << ans << endl;
}