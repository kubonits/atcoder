#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  long long n, m, l, r, mid, x[100000], p, flag;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  l = 0LL;
  r = 2000000000LL;
  while (l <= r) {
    flag = 1LL;
    mid = (l + r) / 2LL;
    p = 0LL;
    for (int i = 0; i < m; i++) {
      if (p + 1 < x[i] - mid) {
        flag = 0LL;
        break;
      }
      p = min(x[i] + mid,
              max(x[i] + (mid - (x[i] - (p + 1LL))) / 2LL,
                  max(x[i], x[i] + mid - 2LL * (x[i] - (p + 1LL)))));
    }
    if (flag && p >= n) {
      r = mid - 1LL;
    } else {
      l = mid + 1LL;
    }
  }
  cout << l << endl;
}