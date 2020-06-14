#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int a[200000], b[200000], cnt;
int n, left[2], right[2], mid;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  if (n % 2) {
    cout << b[n / 2] - a[n / 2] + 1 << endl;
  } else {
    cout << b[(n - 1) / 2] + b[(n - 1) / 2 + 1] -
                (a[(n - 1) / 2] + a[(n - 1) / 2 + 1]) + 1
         << endl;
  }
}