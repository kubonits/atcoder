#include <algorithm>
#include <iostream>
using namespace std;

int a[100000], b[100000], c[100000], d[100001];
int main() {
  int n, t, sum = 0;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    c[i] = a[i] - b[i];
    sum += a[i];
  }
  sort(c, c + n);
  d[0] = 0;
  if (sum <= t) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    d[i + 1] = d[i] + c[n - 1 - i];
    if (sum - d[i + 1] <= t) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}