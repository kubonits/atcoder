#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, x, y, a[100];
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      x += a[n - 1 - i];
    } else {
      y += a[n - 1 - i];
    }
  }
  if (x == y) {
    cout << "Draw" << endl;
  } else if (x > y) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
}