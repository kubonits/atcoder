#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, a[100000], sum = 0, b[3] = {-1, -1, -1}, c[3] = {};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum ^= a[i];
  }
  sort(a, a + n);
  if (a[n - 1] == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  b[0] = a[0];
  c[0] = 1;
  int p = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == b[p]) {
      c[p]++;
    } else {
      if (!(c[p] == n / 3 * 2 || c[p] == n / 3)) {
        cout << "No" << endl;
        return 0;
      }
      p++;
      b[p] = a[i];
      c[p] = 1;
      if (p == 3) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  if (b[0] == 0 && c[0] == n / 3 && c[1] == n / 3 * 2 ||
      (b[0] ^ b[1] ^ b[2]) == 0 && c[0] == c[1] && c[1] == c[2]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}