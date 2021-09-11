#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, a[50], ans = -100000, maxi, p, sum;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    maxi = -100000;
    p = -1;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        sum = 0;
        for (int k = min(i, j) + 1; k <= max(i, j); k += 2) {
          sum += a[k];
        }
        if (sum > maxi) {
          maxi = sum;
          p = j;
        }
      }
    }
    sum = 0;
    for (int j = min(p, i); j <= max(p, i); j += 2) {
      sum += a[j];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
}