#include <iostream>
using namespace std;
int main() {
  int n, a[200000], b[200000], p = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i < n; i++) {
    if (p == i) {
      i++;
      if (i >= n) {
        break;
      }
    }
    if ((a[i] + b[p] - 1) / b[p] > (a[p] + b[i] - 1) / b[i]) {
      p = i;
    } else if ((a[i] + b[p] - 1) / b[p] == (a[p] + b[i] - 1) / b[i]) {
      p = i + 1;
    }
  }
  if (p > n - 1) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (i != p && (a[i] + b[p] - 1) / b[p] >= (a[p] + b[i] - 1) / b[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << p + 1 << endl;
}