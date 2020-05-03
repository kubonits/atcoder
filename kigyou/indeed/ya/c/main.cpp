#include <iostream>
using namespace std;
int n, sum[1000001] = {}, s, k, l, r, mid, q;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s) {
      sum[s]++;
    }
  }
  for (int i = 999999; i >= 0; i--) {
    sum[i] += sum[i + 1];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> k;
    l = 0;
    r = 1000000;
    while (l <= r) {
      mid = (l + r) / 2;
      if (sum[mid] <= k) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << l << endl;
  }
}