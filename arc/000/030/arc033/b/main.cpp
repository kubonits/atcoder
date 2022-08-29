#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int n, m, a[100000], b[100000];
  double cnt1 = 0.0, cnt2 = 0.0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  int ap = 0, bp = 0;
  while (ap < n || bp < m) {
    if (ap == n) {
      bp++;
      cnt1++;
    } else if (bp == m) {
      ap++;
      cnt1++;
    } else if (a[ap] > b[bp]) {
      bp++;
      cnt1++;
    } else if (a[ap] < b[bp]) {
      ap++;
      cnt1++;
    } else {
      ap++;
      bp++;
      cnt1++;
      cnt2++;
    }
  }
  cout << fixed << setprecision(7) << cnt2 / cnt1 << endl;
}