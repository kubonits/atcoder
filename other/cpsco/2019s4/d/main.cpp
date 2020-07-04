#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k, l, r, mid;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  v.push_back(v.back() + 1);
  l = 1;
  r = n;
  while (l <= r) {
    mid = (l + r) / 2;
    int cnt = 0, cnt2 = 0;
    int p = v[0];
    for (int i = 0; i < n; i++) {
      if (p == v[i]) {
        cnt++;
        if (cnt > mid) {
          cnt2++;
          cnt = 0;
          p = v[i + 1];
        }
      } else {
        cnt = 1;
        p = v[i];
      }
    }
    if (cnt2 <= k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}